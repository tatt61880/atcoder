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

    const submissionsList = await getSubmissionsList(baseUrl);

    if (submissionsList === null) {
      const p = document.createElement('p');
      p.textContent = '提出データの読み込みに失敗しました。';
      contentsElem.replaceChildren(p);
      return;
    }

    contentsElem.replaceChildren();

    if (targetContestId === null) {
      await appendAcList(contentsElem, submissionsList);
    } else {
      await appendSubmissionInfo(
        contentsElem,
        submissionsList,
        baseUrl,
        targetContestId,
        targetProblemId
      );
    }
  }

  function appendProblemNameOption(contentsElem) {
    const storageKey = 'showProblemName';

    const label = document.createElement('label');
    label.className = 'option-label';

    const input = document.createElement('input');
    input.id = 'show-problem-name-checkbox';
    input.type = 'checkbox';
    input.checked = localStorage.getItem(storageKey) === 'true';

    label.appendChild(input);
    label.append('問題名を表示する');
    contentsElem.appendChild(label);

    input.addEventListener('change', () => {
      localStorage.setItem(storageKey, input.checked ? 'true' : 'false');
      updateProblemNameVisibility();
    });

    return updateProblemNameVisibility;

    function updateProblemNameVisibility() {
      const checked = input.checked;
      for (const a of document.querySelectorAll('a.submit-link')) {
        const problemIndex = a.dataset.problemIndex;
        const problemName = a.dataset.problemName;
        a.textContent = checked
          ? `${problemIndex}: ${problemName}`
          : problemIndex;
      }
    }
  }

  // ACコード一覧
  async function appendAcList(contentsElem, submissionsList) {
    const updateProblemNameVisibility = appendProblemNameOption(contentsElem);

    const tablePager = window.TablePager.create(contentsElem, {
      storageKey: 'contestPageSize',
      itemName: 'コンテスト',
      pageSizeOptions: [
        { value: '5', text: '5コンテスト' },
        { value: '10', text: '10コンテスト' },
        { value: '20', text: '20コンテスト' },
        { value: '50', text: '50コンテスト' },
        { value: '100', text: '100コンテスト' },
        { value: 'all', text: '全件' },
      ],
    });

    // 件数
    {
      const p = document.createElement('p');
      contentsElem.appendChild(p);

      const problemSet = new Set();
      for (const submission of submissionsList) {
        const problemId = submission.problem_id;
        problemSet.add(problemId);
      }

      p.setAttribute('id', 'total-num');

      const totalNumSpan = document.createElement('span');
      totalNumSpan.textContent = `計${submissionsList.length}問`;
      p.appendChild(totalNumSpan);

      const totalNumNoteSpan = document.createElement('span');
      totalNumNoteSpan.classList.add('total-num-note');
      totalNumNoteSpan.textContent = `（問題IDの重複分を除くと${problemSet.size}問）`;
      p.appendChild(totalNumNoteSpan);
    }

    const table = document.createElement('table');
    table.className = 'main-table';
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

      contestMap.get(contestId).push(submission);
    }

    const contestEntries = Array.from(contestMap.entries());

    tablePager.setOnChange(renderContestTable);
    renderContestTable();

    function renderContestTable() {
      tbody.replaceChildren();

      tablePager.update(contestEntries.length);

      const beginIndex = tablePager.getBeginIndex();
      const endIndex = tablePager.getEndIndex(contestEntries.length);

      for (const [contestId, submissions] of contestEntries.slice(
        beginIndex,
        endIndex
      )) {
        const tr = tbody.insertRow();

        // コンテスト毎のまとめ
        {
          const url = getTaskPageUrl(contestId);
          const text = contestTitleMap.get(contestId);
          const td = tr.insertCell();
          td.appendChild(createInternalLink(url, text));
        }

        // 個別のソースコード
        {
          const td = tr.insertCell();

          for (const submission of submissions) {
            const problemId = submission.problem_id;
            const problemIndex = submission.problem_index;
            const url = getTaskPageUrl(contestId, problemId);
            const cpId = `${contestId}/${problemId}`;
            const text = problemIndexMap.get(cpId);
            const a = createInternalLink(url, text);

            a.classList.add('submit-link');
            a.textContent = problemIndex;
            a.title = submission.name;
            a.dataset.problemIndex = problemIndex;
            a.dataset.problemName = submission.name;
            td.appendChild(a);
          }
        }
      }

      updateProblemNameVisibility();
    }
  }

  // 提出内容
  async function appendSubmissionInfo(
    contentsElem,
    submissionsList,
    baseUrl,
    targetContestId,
    targetProblemId
  ) {
    let foundCount = 0;

    for (const submission of submissionsList) {
      const contestId = submission.contest_id;
      if (contestId !== targetContestId) continue;

      const problemId = submission.problem_id;
      if (targetProblemId !== null && problemId !== targetProblemId) continue;

      foundCount++;

      const contestTitle = submission.contest_title;
      const problemIndex = submission.problem_index;
      const name = submission.name;

      // コンテスト情報
      if (foundCount === 1) {
        if (targetProblemId === null) {
          document.title = `${contestTitle} - ${pageTitle}`;
        } else {
          document.title = `${problemIndex} - ${name} - ${pageTitle}`;
        }

        const h2 = document.createElement('h2');
        h2.textContent = `${contestTitle}`;
        contentsElem.appendChild(h2);

        const contestUrl = getContestUrl(contestId);
        appendExternalLink(contentsElem, 'コンテストリンク: ', contestUrl);
      }

      // 問題名
      {
        const h3 = document.createElement('h3');
        h3.textContent = `${problemIndex} - ${name}`;
        contentsElem.appendChild(h3);
      }

      // 問題URL
      {
        const problemUrl = getProblemUrl(contestId, problemId);
        appendExternalLink(contentsElem, '問題リンク: ', problemUrl);
      }

      const [submissionUrl, src] = await Promise.all([
        getSubmissionUrl(baseUrl, contestId, problemId),
        getSrc(baseUrl, contestId, problemId),
      ]);

      // 提出URL
      {
        appendExternalLink(contentsElem, '提出リンク: ', submissionUrl);
      }

      // 提出したソースコード
      {
        if (src !== null) {
          const h4 = document.createElement('h4');
          h4.textContent = '提出したソースコード (言語: Kuin)';
          contentsElem.appendChild(h4);

          const pre = document.createElement('pre');
          pre.classList.add('code');
          contentsElem.appendChild(pre);

          const editor = tryElemToKuinEditor(pre);
          if (editor !== null) {
            editor.setValue(src);
            editor.navigateTo(0, 0);
          } else {
            pre.textContent = src;
          }
        } else {
          const p = document.createElement('p');
          p.textContent = 'ソースコードの読み込みに失敗しました。';
          contentsElem.appendChild(p);
        }
      }
    }

    if (foundCount === 0) {
      const p = document.createElement('p');
      p.textContent = '該当する提出データが見つかりませんでした。';
      contentsElem.appendChild(p);
    }
  }

  function appendExternalLink(parentElem, labelText, url) {
    const p = document.createElement('p');
    p.classList.add('external-url');
    parentElem.append(p);

    {
      const span = document.createElement('span');
      span.classList.add('url-label');
      span.textContent = labelText;
      p.append(span);
    }

    if (url === null) {
      const span = document.createElement('span');
      span.textContent = 'URLの読み込みに失敗しました。';
      span.className = 'link-load-error';

      p.appendChild(span);
    } else {
      const a = document.createElement('a');
      a.href = url;
      a.target = '_blank';
      a.rel = 'noopener noreferrer';

      const urlText = String(url).replace(
        new RegExp('^https://atcoder.jp/contests/[^/]+(/.+)'),
        '$1'
      );
      appendUrlTextWithBreaks(a, urlText);
      p.appendChild(a);
    }
  }

  function appendUrlTextWithBreaks(parentElem, urlText) {
    const parts = String(urlText).split('/');

    parentElem.textContent = '';

    parts.forEach((part, i) => {
      if (i !== 0) {
        parentElem.append('/');
        parentElem.append(document.createElement('wbr'));
      }
      parentElem.append(part);
    });
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

  function tryElemToKuinEditor(elem) {
    if (window.ace === undefined) {
      return null;
    }

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

  function createInternalLink(url, text = url) {
    const a = document.createElement('a');

    a.href = url;
    a.textContent = text;

    return a;
  }

  function getContestUrl(contestId) {
    if (contestId === null) return null;

    return new URL(
      `contests/${encodeURIComponent(contestId)}/`,
      'https://atcoder.jp/'
    );
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

  function parseUrlFile(text) {
    const match = text.match(/^URL=(.+)$/m);
    if (match === null) return null;

    return match[1].trim();
  }

  async function getSubmissionUrl(baseUrl, contestId, problemId) {
    const res = await fetchText(
      new URL(
        'submissions/' +
          `${encodeURIComponent(contestId)}/` +
          `${encodeURIComponent(problemId)}.url`,
        baseUrl
      )
    );

    if (res !== null) {
      return parseUrlFile(res);
    }

    return null;
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
      if (response.ok) return response;
    } catch (error) {
      console.error(error);
    }

    return null;
  }

  async function fetchText(url) {
    const response = await fetchResponse(url);
    if (response === null) return null;

    return await response.text();
  }

  async function fetchJson(url) {
    const response = await fetchResponse(url);
    if (response === null) return null;

    try {
      return await response.json();
    } catch (error) {
      console.error(error);
      return null;
    }
  }
})();
