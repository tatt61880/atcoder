(function () {
  'use strict';

  document.addEventListener('DOMContentLoaded', onloadApp);
  return;
  // ==========================================================================

  async function onloadApp() {
    const urlQueryParams = analyzeUrl();
    const base = urlQueryParams.base;
    const tasks = urlQueryParams.tasks;

    const contents = document.getElementById('data');
    if (contents === null) {
      console.error('Error! #contents === null');
      return;
    }

    if (tasks === null) {
      await appendAcList(contents, base);
    } else {
      await appendTasks(contents, base, tasks);
    }
  }

  // ACコード一覧
  async function appendAcList(contents, base) {
    const h1 = document.createElement('h1');
    h1.innerText = '各問の最新ACコード一覧';
    contents.appendChild(h1);
    contents.appendChild(document.createElement('hr'));

    const p = document.createElement('p');
    contents.appendChild(p);

    const table = document.createElement('table');
    const thead = document.createElement('thead');
    contents.appendChild(table);
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
    p.innerText = `${submissionsList.length}件`;
    p.setAttribute('id', 'total-num');

    const contestMap = new Map();

    for (const submission of submissionsList) {
      const problemId = submission.problem_id;
      const contestId = submission.contest_id;

      const m = /(?:.*)_(?<id>.*)/.exec(problemId);
      if (!m) continue;

      const { id } = m.groups;

      if (!contestMap.has(contestId)) {
        contestMap.set(contestId, []);
      }
      contestMap.get(contestId).push({ problemId, id });
    }

    for (const [contest, problems] of contestMap) {
      const tr = tbody.insertRow();

      {
        const td = tr.insertCell();
        const a = document.createElement('a');
        a.href = `?tasks=${problems
          .map(({ problemId }) => problemId)
          .join(',')}`;
        a.innerText = contest;
        td.appendChild(a);
      }

      {
        const td = tr.insertCell();

        for (const { problemId, id } of problems) {
          const a = document.createElement('a');
          a.href = `?tasks=${problemId}`;
          a.innerText = id;
          a.classList.add('submit-link');
          td.appendChild(a);
        }
      }
    }
  }

  // 提出内容
  async function appendTasks(contents, base, tasks) {
    const submissionsList = await getSubmissionsList(base);
    const problemContestMap = new Map();
    for (const submission of submissionsList) {
      const problemId = submission.problem_id;
      const contestId = submission.contest_id;
      problemContestMap[problemId] = contestId;
    }

    for (const task of tasks.split(',')) {
      // ページタイトル
      {
        let title = await getTitle(task);
        if (title === null) {
          title = task;
        }
        document.title = title;

        const h1 = document.createElement('h2');
        h1.innerText = title;
        contents.appendChild(h1);
      }

      // 問題URL
      {
        const contestId = problemContestMap[task];
        const problemUrl = getProblemUrl(contestId, task);
        const p = document.createElement('p');
        p.classList.add('narrow');
        p.innerText = '問題URL: ';
        contents.appendChild(p);

        if (problemUrl !== null) {
          const a = document.createElement('a');
          a.href = problemUrl;
          a.innerText = problemUrl;
          p.appendChild(a);
        }
      }

      // 提出したソースコード
      {
        const src = await getSrc(base, task);
        if (src !== null) {
          const h2 = document.createElement('h3');
          h2.innerText = '提出したソースコード (言語: Kuin)';
          contents.appendChild(h2);

          const pre = document.createElement('pre');
          pre.classList.add('code');
          contents.appendChild(pre);

          const editor = elemToKuinEditor(pre);
          editor.setValue(src);
          editor.navigateTo(0, 0);
        }

        contents.appendChild(document.createElement('hr'));
      }
    }
  }

  function analyzeUrl() {
    const res = {
      base: '',
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

  async function getTitle(task) {
    if (task === null) return null;
    const m = /(?<contest>.*)_(?<id>.*)/.exec(task);
    if (m !== null) {
      return `${m.groups.contest} - ${m.groups.id}`;
    } else {
      return null;
    }
  }

  function getProblemUrl(contestId, task) {
    if (contestId === null) return null;
    if (task === null) return null;
    return `https://atcoder.jp/contests/${contestId}/tasks/${task}`;
  }

  // async function getSubmissionUrl(base, task) {
  //   const res = await fetchText(`${base}submissions/${task}/submission.url`);
  //   if (res !== null) {
  //     return res.split('=')[1];
  //   }
  //   return null;
  // }

  // async function getEditorial(base, task) {
  //   return await fetchText(`${base}md/${task}.md`);
  // }

  async function getSrc(base, task) {
    return await fetchText(`${base}submissions/${task}/main.kn`);
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
