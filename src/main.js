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
    h1.innerText = pageTitle;
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

    const submissionsList = await getSubmissionsList(baseUrl);
    if (submissionsList === null) {
      const p = document.createElement('p');
      p.innerText = '提出データの読み込みに失敗しました。';
      contentsElem.appendChild(p);
      return;
    }

    {
      const problemSet = new Set();
      for (const submission of submissionsList) {
        const problemId = submission.problem_id;
        problemSet.add(problemId);
      }

      p.setAttribute('id', 'total-num');

      const totalNumSpan = document.createElement('span');
      totalNumSpan.innerText = `${submissionsList.length}件`;
      p.appendChild(totalNumSpan);

      const totalNumNoteSpan = document.createElement('span');
      totalNumNoteSpan.classList.add('total-num-note');
      totalNumNoteSpan.innerText = ` (問題IDの重複分を除くと${problemSet.size}件)`;
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
        a.href = `?contest=${encodeURIComponent(contestId)}`;
        a.innerText = contestTitleMap.get(contestId);
        td.appendChild(a);
      }

      // 個別のソースコード
      {
        const td = tr.insertCell();

        for (const problemId of problemsId) {
          const a = document.createElement('a');
          a.href =
            `?contest=${encodeURIComponent(contestId)}` +
            `&task=${encodeURIComponent(problemId)}`;
          const cpId = `${contestId}/${problemId}`;
          a.innerText = problemIndexMap.get(cpId);
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
      h1.innerText = pageTitle;
      contentsElem.appendChild(h1);
    }

    const submissionsList = await getSubmissionsList(baseUrl);
    if (submissionsList === null) {
      const p = document.createElement('p');
      p.innerText = '提出データの読み込みに失敗しました。';
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
        h2.innerText = title;
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
        const src = await getSrc(baseUrl, contestId, problemId);
        if (src !== null) {
          const h3 = document.createElement('h3');
          h3.innerText = '提出したソースコード (言語: Kuin)';
          contentsElem.appendChild(h3);

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

    if (!found) {
      const p = document.createElement('p');
      p.innerText = '該当する提出データが見つかりませんでした。';
      contentsElem.appendChild(p);
    }
  }

  function analyzeUrl() {
    const params = new URLSearchParams(location.search);

    return {
      baseUrl: `${location.origin}${location.pathname}`,
      targetContestId: params.get('contest'),
      targetProblemId: params.get('task'),
    };
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

  async function getSubmissionsList(baseUrl) {
    return await fetchJson(`${baseUrl}submissions/kuinSubmissions.json`);
  }

  function getProblemUrl(contestId, problemId) {
    if (contestId === null) return null;
    if (problemId === null) return null;
    return (
      'https://atcoder.jp/' +
      `contests/${encodeURIComponent(contestId)}/` +
      `tasks/${encodeURIComponent(problemId)}`
    );
  }

  async function getSrc(baseUrl, contestId, problemId) {
    return await fetchText(
      `${baseUrl}submissions/` +
        `${encodeURIComponent(contestId)}/` +
        `${encodeURIComponent(problemId)}.kn`
    );
  }

  async function fetchText(url) {
    // 通信失敗やレスポンス本文の読み取り失敗時は null を返し、呼び出し側でエラー表示する。
    try {
      // ソースコードは更新頻度が高いため、常に再取得する。
      const response = await fetch(url, { cache: 'no-store' });
      if (!response.ok) return null;
      return await response.text();
    } catch (error) {
      console.error(error);
      return null;
    }
  }

  async function fetchJson(url) {
    // 通信失敗やJSONの破損時は null を返し、呼び出し側でエラー表示する。
    try {
      // 提出一覧は更新頻度が高いため、常に再取得する。
      const response = await fetch(url, { cache: 'no-store' });
      if (!response.ok) return null;
      return await response.json();
    } catch (error) {
      console.error(error);
      return null;
    }
  }
})();
