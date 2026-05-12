(function () {
  'use strict';

  const pageTitle = 'tatt61880によるAtCoderでのACコード';

  document.addEventListener('DOMContentLoaded', onloadApp);
  return;
  // ==========================================================================

  async function onloadApp() {
    const urlQueryParams = analyzeUrl();
    const baseUrl = urlQueryParams.baseUrl;
    const targetContestId = urlQueryParams.targetContestId;
    const targetProblemId = urlQueryParams.targetProblemId;

    const contentsElem = document.getElementById('contents-data');
    if (contentsElem === null) {
      console.error('Error! #contents-data === null');
      return;
    }

    if (targetContestId === null) {
      await appendAcList(contentsElem, baseUrl);
    } else {
      await appendTasks(
        contentsElem,
        baseUrl,
        targetContestId,
        targetProblemId
      );
    }
  }

  // ACコード一覧
  async function appendAcList(contentsElem, baseUrl) {
    const h1 = document.createElement('h1');
    h1.textContent = pageTitle;
    contentsElem.appendChild(h1);

    const submissionsList = await getSubmissionsList(baseUrl);

    if (submissionsList === null) {
      const p = document.createElement('p');
      p.textContent = '提出データの読み込みに失敗しました。';
      contentsElem.appendChild(p);
      return;
    }

    const p = document.createElement('p');
    contentsElem.appendChild(p);

    const table = document.createElement('table');
    contentsElem.appendChild(table);

    const thead = document.createElement('thead');
    table.appendChild(thead);

    const tr = thead.insertRow();

    {
      const td = document.createElement('th');
      td.textContent = 'コンテスト毎のまとめ';
      tr.appendChild(td);
    }

    {
      const td = document.createElement('th');
      td.textContent = '個別のソースコード';
      tr.appendChild(td);
    }

    const tbody = document.createElement('tbody');
    table.appendChild(tbody);

    {
      const problemSet = new Set();
      for (const submission of submissionsList) {
        const problemId = submission.problem_id;
        problemSet.add(problemId);
      }

      p.setAttribute('id', 'total-num');

      const totalNumSpan = document.createElement('span');
      totalNumSpan.textContent = `${submissionsList.length}件`;
      p.appendChild(totalNumSpan);

      const totalNumNoteSpan = document.createElement('span');
      totalNumNoteSpan.classList.add('total-num-note');
      totalNumNoteSpan.textContent = `（問題IDの重複分を除くと${problemSet.size}件）`;
      p.appendChild(totalNumNoteSpan);
    }

    const contestMap = new Map();
    const contestTitleMap = new Map();
    const problemIndexMap = new Map();

    for (const submission of submissionsList) {
      const contestId = submission.contest_id;
      const problemId = submission.problem_id;

      contestTitleMap.set(contestId, submission.contest_title);
      const problemIndex = submission.problem_index;

      const cpId = `${contestId}/${problemId}`;
      problemIndexMap.set(cpId, problemIndex);

      if (!contestMap.has(contestId)) {
        contestMap.set(contestId, []);
      }
      contestMap.get(contestId).push(problemId);
    }

    for (const [contestId, problemsId] of contestMap) {
      const tr = tbody.insertRow();

      // コンテスト毎のまとめ
      {
        const td = tr.insertCell();
        const a = document.createElement('a');
        a.href = getTaskPageUrl(contestId);
        a.textContent = contestTitleMap.get(contestId);
        td.appendChild(a);
      }

      // 個別のソースコード
      {
        const td = tr.insertCell();

        for (const problemId of problemsId) {
          const a = document.createElement('a');
          a.href = getTaskPageUrl(contestId, problemId);
          const cpId = `${contestId}/${problemId}`;
          a.textContent = problemIndexMap.get(cpId);
          a.classList.add('submit-link');
          td.appendChild(a);
        }
      }
    }
  }

  // 提出内容
  async function appendTasks(
    contentsElem,
    baseUrl,
    targetContestId,
    targetProblemId
  ) {
    {
      const h1 = document.createElement('h1');
      h1.textContent = pageTitle;
      contentsElem.appendChild(h1);
    }

    const submissionsList = await getSubmissionsList(baseUrl);
    if (submissionsList === null) {
      const p = document.createElement('p');
      p.textContent = '提出データの読み込みに失敗しました。';
      contentsElem.appendChild(p);
      return;
    }

    let found = false;

    for (const submission of submissionsList) {
      const contestId = submission.contest_id;
      if (contestId !== targetContestId) continue;

      const problemId = submission.problem_id;
      if (targetProblemId !== null && problemId !== targetProblemId) continue;

      found = true;

      const contestTitle = submission.contest_title;
      const problemIndex = submission.problem_index;
      const name = submission.name;

      // ページタイトル
      {
        const title = `${contestTitle}: ${problemIndex} - ${name}`;

        const h2 = document.createElement('h2');
        h2.textContent = title;
        contentsElem.appendChild(h2);

        if (targetProblemId === null) {
          document.title = `${contestTitle} - ${pageTitle}`;
        } else {
          document.title = `${title} - ${pageTitle}`;
        }
      }

      // 問題URL
      {
        const problemUrl = getProblemUrl(contestId, problemId);
        const p = document.createElement('p');
        p.classList.add('narrow');
        p.textContent = '問題URL: ';
        contentsElem.appendChild(p);

        if (problemUrl !== null) {
          const a = document.createElement('a');
          a.href = problemUrl;
          a.textContent = problemUrl;
          p.appendChild(a);
        }
      }

      // 提出したソースコード
      {
        const src = await getSrc(baseUrl, contestId, problemId);
        if (src !== null) {
          const h3 = document.createElement('h3');
          h3.textContent = '提出したソースコード (言語: Kuin)';
          contentsElem.appendChild(h3);

          const pre = document.createElement('pre');
          pre.classList.add('code');
          contentsElem.appendChild(pre);

          const editor = elemToKuinEditor(pre);
          editor.setValue(src);
          editor.navigateTo(0, 0);
        } else {
          const p = document.createElement('p');
          p.textContent = 'ソースコードの読み込みに失敗しました。';
          contentsElem.appendChild(p);
        }

        contentsElem.appendChild(document.createElement('hr'));
      }
    }

    if (!found) {
      const p = document.createElement('p');
      p.textContent = '該当する提出データが見つかりませんでした。';
      contentsElem.appendChild(p);
    }
  }

  function analyzeUrl() {
    const params = new URLSearchParams(location.search);

    return {
      baseUrl: new URL('./', location.href),
      targetContestId: params.get('contest'),
      targetProblemId: params.get('task'),
    };
  }

  function getTaskPageUrl(contestId, problemId = null) {
    const params = new URLSearchParams();
    params.set('contest', contestId);
    if (problemId !== null) params.set('task', problemId);
    return `?${params.toString()}`;
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

  function getProblemUrl(contestId, problemId) {
    if (contestId === null) return null;
    if (problemId === null) return null;

    return new URL(
      `contests/${encodeURIComponent(contestId)}/` +
        `tasks/${encodeURIComponent(problemId)}`,
      'https://atcoder.jp/'
    );
  }

  async function getSubmissionsList(baseUrl) {
    return await fetchJson(
      new URL('submissions/kuinSubmissions.json', baseUrl)
    );
  }

  async function getSrc(baseUrl, contestId, problemId) {
    return await fetchText(
      new URL(
        'submissions/' +
          `${encodeURIComponent(contestId)}/` +
          `${encodeURIComponent(problemId)}.kn`,
        baseUrl
      )
    );
  }

  async function fetchResponse(url) {
    try {
      const response = await fetch(url, { cache: 'no-store' });
      if (!response.ok) return null;
      return response;
    } catch (error) {
      console.error(error);
      return null;
    }
  }

  async function fetchText(url) {
    const response = await fetchResponse(url);
    return response === null ? null : await response.text();
  }

  async function fetchJson(url) {
    const response = await fetchResponse(url);
    return response === null ? null : await response.json();
  }
})();
