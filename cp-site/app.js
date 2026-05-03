const App = (() => {
  const CODE_EXTS = new Set(['cpp', 'c', 'js', 'py', 'java', 'sh', 'sql']);

  async function loadFile(item) {
    const content = document.getElementById('content');
    const breadcrumb = document.getElementById('breadcrumb');
    const copyBtn = document.getElementById('copy-btn');

    breadcrumb.textContent = item.path.replace('content/', '');
    content.innerHTML = '<p style="color:var(--text-muted);padding:8px 0">Loading…</p>';
    copyBtn.style.display = '';

    let text;
    try {
      const res = await fetch(item.path);
      if (!res.ok) throw new Error(res.statusText);
      text = await res.text();
    } catch (e) {
      content.innerHTML = `<p style="color:#f38ba8">Failed to load file: ${e.message}</p>`;
      return;
    }

    const ext = item.path.split('.').pop().toLowerCase();

    if (ext === 'md') {
      copyBtn.style.display = 'none';
      const div = document.createElement('div');
      div.className = 'md-body';
      div.innerHTML = marked.parse(text, { gfm: true, breaks: false });
      div.querySelectorAll('pre code').forEach(el => hljs.highlightElement(el));
      content.innerHTML = '';
      content.appendChild(div);
    } else if (CODE_EXTS.has(ext)) {
      const pre = document.createElement('pre');
      const code = document.createElement('code');
      const lang = ext === 'cpp' || ext === 'c' ? 'cpp' : ext;
      code.className = `language-${lang}`;
      code.textContent = text;
      pre.appendChild(code);
      content.innerHTML = '';
      content.appendChild(pre);
      hljs.highlightElement(code);
    } else {
      const pre = document.createElement('pre');
      pre.style.whiteSpace = 'pre-wrap';
      pre.textContent = text;
      content.innerHTML = '';
      content.appendChild(pre);
    }

    setupCopyBtn(text);
    content.scrollTop = 0;
  }

  function setupCopyBtn(text) {
    const btn = document.getElementById('copy-btn');
    btn.textContent = 'Copy';
    btn.classList.remove('copied');
    btn.onclick = () => {
      navigator.clipboard.writeText(text).then(() => {
        btn.textContent = 'Copied!';
        btn.classList.add('copied');
        setTimeout(() => { btn.textContent = 'Copy'; btn.classList.remove('copied'); }, 1800);
      });
    };
  }

  function init() {
    document.addEventListener('file-selected', e => loadFile(e.detail));

    document.getElementById('hamburger').addEventListener('click', () => {
      document.getElementById('sidebar').classList.toggle('collapsed');
    });

    const fileParam = new URLSearchParams(location.search).get('file');
    if (fileParam) {
      Sidebar.setActive(fileParam);
    }
  }

  return { init };
})();

document.addEventListener('DOMContentLoaded', async () => {
  await Sidebar.init();
  Search.init();
  App.init();
});
