// Markdown parsing utilities (browser-side wrapper for marked.js)
// Usage: import parseMarkdown from './scripts/markdownParser.js' (ES module) or
//        call parseMarkdown(text) after loading marked.js via CDN.

function parseMarkdown(text) {
  if (typeof marked === 'undefined') throw new Error('marked.js not loaded');
  return marked.parse(text, {
    gfm: true,
    breaks: false,
    renderer: buildRenderer(),
  });
}

function buildRenderer() {
  const r = new marked.Renderer();

  r.code = (code, lang) => {
    const language = (lang || 'plaintext').split(' ')[0];
    const highlighted = (typeof hljs !== 'undefined' && hljs.getLanguage(language))
      ? hljs.highlight(code, { language }).value
      : escapeHtml(code);
    return `<pre><code class="hljs language-${language}">${highlighted}</code></pre>`;
  };

  r.link = (href, title, text) => {
    const t = title ? ` title="${title}"` : '';
    const ext = href && !href.startsWith('#') && !href.startsWith('/');
    return `<a href="${href}"${t}${ext ? ' target="_blank" rel="noopener"' : ''}>${text}</a>`;
  };

  return r;
}

function escapeHtml(str) {
  return str.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
}

if (typeof module !== 'undefined') module.exports = { parseMarkdown };
