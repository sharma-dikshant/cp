const Sidebar = (() => {
  let manifest = [];
  let activeFile = null;

  async function init() {
    const res = await fetch('data/manifest.json');
    manifest = await res.json();
    render(manifest);
    buildQuickLinks(manifest);
    window.addEventListener('popstate', () => {
      const p = new URLSearchParams(location.search).get('file');
      if (p) setActive(p);
    });
  }

  function render(items) {
    const nav = document.getElementById('nav-tree');
    nav.innerHTML = '';
    const tree = buildTree(items);
    for (const [cat, sub] of Object.entries(tree)) {
      nav.appendChild(makeCategory(cat, sub));
    }
  }

  function buildTree(items) {
    const tree = {};
    for (const item of items) {
      const parts = item.path.replace('content/', '').split('/');
      const cat = parts[0];
      if (!tree[cat]) tree[cat] = {};
      if (parts.length === 2) {
        if (!tree[cat].__files) tree[cat].__files = [];
        tree[cat].__files.push(item);
      } else {
        const sub = parts[1];
        if (!tree[cat][sub]) tree[cat][sub] = [];
        tree[cat][sub].push(item);
      }
    }
    return tree;
  }

  function makeCategory(name, sub) {
    const wrap = document.createElement('div');
    wrap.className = 'nav-category open';
    wrap.dataset.category = name;

    const header = document.createElement('div');
    header.className = 'nav-category-header';
    header.innerHTML = `<span class="arrow">&#9658;</span> ${fmt(name)}`;
    header.addEventListener('click', () => wrap.classList.toggle('open'));
    wrap.appendChild(header);

    const body = document.createElement('div');
    body.className = 'nav-category-body';

    if (sub.__files) {
      body.appendChild(makeFileList(sub.__files, false));
    }
    for (const [subName, files] of Object.entries(sub)) {
      if (subName === '__files') continue;
      body.appendChild(makeSubcategory(subName, files));
    }
    wrap.appendChild(body);
    return wrap;
  }

  function makeSubcategory(name, files) {
    const wrap = document.createElement('div');
    wrap.className = 'nav-subcategory open';

    const header = document.createElement('div');
    header.className = 'nav-subcategory-header';
    header.innerHTML = `<span class="arrow">&#9658;</span> ${fmt(name)}`;
    header.addEventListener('click', () => wrap.classList.toggle('open'));
    wrap.appendChild(header);
    wrap.appendChild(makeFileList(files, true));
    return wrap;
  }

  function makeFileList(files, inSub) {
    const ul = document.createElement('ul');
    ul.className = 'nav-files';
    for (const item of files) {
      const li = document.createElement('li');
      li.className = 'nav-file' + (inSub ? ' in-sub' : '');
      li.dataset.path = item.path;
      li.textContent = item.title;
      li.addEventListener('click', () => selectFile(item));
      ul.appendChild(li);
    }
    return ul;
  }

  function buildQuickLinks(items) {
    const ul = document.getElementById('quick-links');
    if (!ul) return;
    const cats = [...new Set(items.map(i => i.category))];
    for (const cat of cats) {
      const li = document.createElement('li');
      const a = document.createElement('a');
      a.textContent = fmt(cat);
      a.addEventListener('click', () => {
        const first = items.find(i => i.category === cat);
        if (first) selectFile(first);
      });
      li.appendChild(a);
      ul.appendChild(li);
    }
  }

  function selectFile(item) {
    activeFile = item.path;
    history.pushState({}, '', `?file=${encodeURIComponent(item.path)}`);
    document.querySelectorAll('.nav-file').forEach(el => {
      el.classList.toggle('active', el.dataset.path === item.path);
    });
    document.dispatchEvent(new CustomEvent('file-selected', { detail: item }));
  }

  function setActive(path) {
    const item = manifest.find(i => i.path === path);
    if (item) selectFile(item);
  }

  function filter(query) {
    const q = query.trim().toLowerCase();
    if (!q) { render(manifest); return; }
    const hits = manifest.filter(i =>
      i.title.toLowerCase().includes(q) ||
      (i.tags || []).some(t => t.includes(q)) ||
      i.path.toLowerCase().includes(q)
    );
    render(hits.map(i => ({
      ...i,
      title: i.title.replace(new RegExp(`(${escRe(q)})`, 'gi'), '<mark>$1</mark>')
    })));
  }

  function fmt(s) {
    return s.replace(/-/g, ' ').replace(/\b\w/g, c => c.toUpperCase());
  }
  function escRe(s) { return s.replace(/[.*+?^${}()|[\]\\]/g, '\\$&'); }

  return { init, filter, setActive, getManifest: () => manifest };
})();
