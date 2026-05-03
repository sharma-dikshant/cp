const Search = (() => {
  function init() {
    const box = document.getElementById('search-box');
    let debounce;
    box.addEventListener('input', () => {
      clearTimeout(debounce);
      debounce = setTimeout(() => Sidebar.filter(box.value), 120);
    });
    box.addEventListener('keydown', e => {
      if (e.key === 'Escape') { box.value = ''; Sidebar.filter(''); }
    });
  }
  return { init };
})();
