(function () {
  'use strict';

  window.TablePager = {
    create,
  };

  return;

  // ==========================================================================

  function create(parentElem, option) {
    const storageKey = option.storageKey;
    const itemName = option.itemName;
    const pageSizeOptions = option.pageSizeOptions;

    let currentPage = 1;
    let onChange = null;

    const container = document.createElement('div');
    container.className = 'table-pager';
    parentElem.appendChild(container);

    const label = document.createElement('span');
    label.className = 'table-pager-label';
    label.textContent = '表示件数: ';
    container.appendChild(label);

    const select = document.createElement('select');
    select.id = 'table-page-size';
    select.name = 'table-page-size';
    label.htmlFor = select.id;
    container.appendChild(select);

    for (const pageSizeOption of pageSizeOptions) {
      const selectOption = document.createElement('option');
      selectOption.value = pageSizeOption.value;
      selectOption.textContent = pageSizeOption.text;
      select.appendChild(selectOption);
    }

    const valueList = pageSizeOptions.map(
      (pageSizeOption) => pageSizeOption.value
    );
    const storedValue = localStorage.getItem(storageKey);
    select.value = valueList.includes(storedValue)
      ? storedValue
      : pageSizeOptions[0].value;

    const status = document.createElement('span');
    status.className = 'table-pager-status';
    container.appendChild(status);

    const prevButton = document.createElement('button');
    prevButton.type = 'button';
    prevButton.textContent = '前へ';
    container.appendChild(prevButton);

    const nextButton = document.createElement('button');
    nextButton.type = 'button';
    nextButton.textContent = '次へ';
    container.appendChild(nextButton);

    select.addEventListener('change', () => {
      localStorage.setItem(storageKey, select.value);
      currentPage = 1;
      callOnChange();
    });

    prevButton.addEventListener('click', () => {
      currentPage--;
      callOnChange();
    });

    nextButton.addEventListener('click', () => {
      currentPage++;
      callOnChange();
    });

    return {
      setOnChange(func) {
        onChange = func;
      },

      getBeginIndex() {
        const pageSize = getPageSize();
        if (pageSize === Infinity) return 0;

        return (currentPage - 1) * pageSize;
      },

      getEndIndex(itemCount) {
        const pageSize = getPageSize();
        if (pageSize === Infinity) return itemCount;

        return Math.min(this.getBeginIndex() + pageSize, itemCount);
      },

      update(itemCount) {
        const pageSize = getPageSize();
        const pageCount = getPageCount(itemCount, pageSize);

        currentPage = Math.min(Math.max(currentPage, 1), pageCount);

        const beginIndex = this.getBeginIndex();
        const endIndex = this.getEndIndex(itemCount);

        if (itemCount === 0) {
          status.textContent = `0${itemName}`;
        } else if (pageSize === Infinity) {
          status.textContent = `全${itemCount}${itemName}`;
        } else {
          status.textContent =
            `${beginIndex + 1}〜${endIndex} / ${itemCount}${itemName} ` +
            `(${currentPage} / ${pageCount}ページ)`;
        }

        prevButton.disabled = currentPage <= 1 || pageSize === Infinity;
        nextButton.disabled = currentPage >= pageCount || pageSize === Infinity;
      },
    };

    function getPageSize() {
      if (select.value === 'all') return Infinity;

      return Number(select.value);
    }

    function getPageCount(itemCount, pageSize) {
      if (pageSize === Infinity) return 1;

      return Math.max(1, Math.ceil(itemCount / pageSize));
    }

    function callOnChange() {
      if (onChange !== null) onChange();
    }
  }
})();
