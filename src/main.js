(function () {
  'use strict';

  document.addEventListener('DOMContentLoaded', onloadApp);
  return;
  // ==========================================================================

  async function onloadApp() {
    const urlQueryParams = analyzeUrl();
    const base = urlQueryParams.base;
    const contestId = urlQueryParams.contest;
    const tasks = urlQueryParams.tasks;

    const contentsElem = document.getElementById('contents-data');
    if (contentsElem === null) {
      console.error('Error! #contents-data === null');
      return;
    }

    if (contestId === null) {
      await appendAcList(contentsElem, base);
    } else {
      await appendTasks(contentsElem, base, contestId, tasks);
    }
  }

  // ACコード一覧
  async function appendAcList(contentsElem, base) {
    const h1 = document.createElement('h1');
    h1.innerText = 'tatt61880によるAtCoderの最新ACコード一覧';
    contentsElem.appendChild(h1);

    const p = document.createElement('p');
    contentsElem.appendChild(p);

    const table = document.createElement('table');
    const thead = document.createElement('thead');
    contentsElem.appendChild(table);
    table.appendChild(thead);
    const tr = thead.insertRow();

    {
      const td = document.createElement('th');
      td.innerText = 'コンテスト毎のまとめ';
      tr.appendChild(td);
    }

    {
      const td = document.createElement('th');
      td.innerText = '個別のソースコード';
      tr.appendChild(td);
    }

    const tbody = document.createElement('tbody');
    table.appendChild(tbody);

    const submissionsList = await getSubmissionsList(base);
    const problemSet = new Set();
    for (const submission of submissionsList) {
      const problemId = submission.problem_id;
      problemSet.add(problemId);
    }
    p.innerText = `${submissionsList.length}件 (重複を除くと${problemSet.size}件)`;
    p.setAttribute('id', 'total-num');

    const contestMap = new Map();
    const contestTitleMap = new Map();
    const problemIndexMap = new Map();

    for (const submission of submissionsList) {
      const contestId = submission.contest_id;
      const problemId = submission.problem_id;
      const cpId = `${contestId}/${problemId}`;
      contestTitleMap[contestId] = submission.contest_title;
      const problemIndex = submission.problem_index;
      problemIndexMap[cpId] = problemIndex;

      const m = /(?:.*)_(?<id>.*)/.exec(problemId);
      if (!m) continue;

      const { id } = m.groups;

      if (!contestMap.has(contestId)) {
        contestMap.set(contestId, []);
      }
      contestMap.get(contestId).push({ problemId, id });
    }

    for (const [contestId, problemsId] of contestMap) {
      const tr = tbody.insertRow();

      // コンテスト毎のまとめ
      {
        const td = tr.insertCell();
        const a = document.createElement('a');
        a.href = `?contest=${contestId}&tasks=${problemsId
          .map(({ problemId }) => problemId)
          .join(',')}`;
        a.innerText = contestTitleMap[contestId];
        // a.innerText = contestId;
        td.appendChild(a);
      }

      // 個別のソースコード
      {
        const td = tr.insertCell();

        for (const { problemId } of problemsId) {
          const a = document.createElement('a');
          a.href = `?contest=${contestId}&tasks=${problemId}`;
          const cpId = `${contestId}/${problemId}`;
          a.innerText = problemIndexMap[cpId];
          a.classList.add('submit-link');
          td.appendChild(a);
        }
      }
    }
  }

  // 提出内容
  async function appendTasks(contentsElem, base, contestId, tasks) {
    const submissionsList = await getSubmissionsList(base);
    const problemContestMap = new Map();
    const problemIndexMap = new Map();
    const problemNameMap = new Map();
    const contestTitleMap = new Map();
    for (const submission of submissionsList) {
      const problemId = submission.problem_id;
      const problemIndex = submission.problem_index;
      const name = submission.name;
      const contestTitle = submission.contest_title;
      problemContestMap[problemId] = contestId;
      problemIndexMap[problemId] = problemIndex;
      problemNameMap[problemId] = name;
      contestTitleMap[problemId] = contestTitle;
    }

    for (const task of tasks.split(',')) {
      // ページタイトル
      {
        const contestTitle = contestTitleMap[task];
        const problemIndex = problemIndexMap[task];
        const name = problemNameMap[task];
        const title = `${contestTitle}: ${problemIndex} - ${name}`;
        document.title = title;

        const h1 = document.createElement('h2');
        h1.innerText = title;
        contentsElem.appendChild(h1);
      }

      // 問題URL
      {
        const contestId = problemContestMap[task];
        const problemUrl = getProblemUrl(contestId, task);
        const p = document.createElement('p');
        p.classList.add('narrow');
        p.innerText = '問題URL: ';
        contentsElem.appendChild(p);

        if (problemUrl !== null) {
          const a = document.createElement('a');
          a.href = problemUrl;
          a.innerText = problemUrl;
          p.appendChild(a);
        }
      }

      // 提出したソースコード
      {
        const contestId = problemContestMap[task];
        const src = await getSrc(base, contestId, task);
        if (src !== null) {
          const h2 = document.createElement('h3');
          h2.innerText = '提出したソースコード (言語: Kuin)';
          contentsElem.appendChild(h2);

          const pre = document.createElement('pre');
          pre.classList.add('code');
          contentsElem.appendChild(pre);

          const editor = elemToKuinEditor(pre);
          editor.setValue(src);
          editor.navigateTo(0, 0);
        }

        contentsElem.appendChild(document.createElement('hr'));
      }
    }
  }

  function analyzeUrl() {
    const res = {
      base: '',
      contest: null,
      tasks: null,
    };

    res.base = location.href.split('?')[0];
    const queryStrs = location.href.split('?')[1];
    if (queryStrs === undefined) return res;
    for (const queryStr of queryStrs.split('&')) {
      const paramArray = queryStr.split('=');
      const paramName = paramArray[0];
      const paramVal = paramArray[1];
      switch (paramName) {
        case 'contest':
          res.contest = paramVal;
          break;
        case 'tasks':
          res.tasks = paramVal;
          break;
      }
    }
    return res;
  }

  function elemToKuinEditor(elem) {
    const editor = window.ace.edit(elem);
    editor.setTheme('ace/theme/kuin');
    editor.session.setMode('ace/mode/kuin');
    editor.setReadOnly(true);
    editor.setOptions({
      maxLines: 10000,
      autoScrollEditorIntoView: true,
      fontSize: '16px',
    });
    editor.resize();
    return editor;
  }

  async function getSubmissionsList(base) {
    return await fetchJson(`${base}submissions/kuinSubmissions.json`);
  }

  function getProblemUrl(contestId, task) {
    if (contestId === null) return null;
    if (task === null) return null;
    return `https://atcoder.jp/contests/${contestId}/tasks/${task}`;
  }

  async function getSrc(base, contestId, task) {
    return await fetchText(`${base}submissions/${contestId}/${task}.kn`);
  }

  async function fetchText(url) {
    const response = await fetch(url, { cache: 'no-store' });
    if (response.ok) return response.text();
    return null;
  }

  async function fetchJson(url) {
    const response = await fetch(url, { cache: 'no-store' });
    if (response.ok) return response.json();
    return null;
  }
})();
