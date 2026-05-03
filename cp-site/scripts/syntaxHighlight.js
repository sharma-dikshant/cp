// Syntax highlight wrapper (browser-side, wraps highlight.js loaded via CDN)
// highlight.js is configured in app.js; this module provides helpers.

function highlightBlock(codeEl) {
  if (typeof hljs === 'undefined') return;
  hljs.highlightElement(codeEl);
}

function highlightAll(container) {
  if (typeof hljs === 'undefined') return;
  container.querySelectorAll('pre code').forEach(el => hljs.highlightElement(el));
}

function highlightText(code, lang) {
  if (typeof hljs === 'undefined') return escapeHtml(code);
  const language = hljs.getLanguage(lang) ? lang : 'plaintext';
  return hljs.highlight(code, { language }).value;
}

function escapeHtml(str) {
  return str.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
}

if (typeof module !== 'undefined') module.exports = { highlightBlock, highlightAll, highlightText };
