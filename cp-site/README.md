# CP Reference

A static web app for browsing competitive programming algorithms, data structures, and notes — with syntax-highlighted code viewing, markdown rendering, and live search.

## Running locally

No build step required. Serve the `cp-site/` directory over HTTP (needed for `fetch()` to work):

```bash
# Option 1 — Python
cd cp-site && python3 -m http.server 8080

# Option 2 — Node
npx serve cp-site

# Option 3 — VS Code Live Server extension
# Right-click index.html → Open with Live Server
```

Then open `http://localhost:8080` in your browser.

## Structure

```
cp-site/
├── index.html          Main page
├── style.css           Dark theme styles
├── app.js              File loading & rendering
├── search.js           Live search (debounced)
├── sidebar.js          Nav tree built from manifest.json
├── data/
│   ├── manifest.json   Content index (auto-generated)
│   └── tags.json       Canonical tag list
├── content/            All algorithm files & notes
│   ├── algorithms/
│   ├── dynamic-programming/
│   ├── graph/
│   ├── trees/
│   ├── number-theory/
│   ├── cpp/
│   ├── sql/
│   └── problems/
├── assets/             Images and gifs
├── templates/
│   └── cp-template.cpp Standard contest template
└── scripts/
    ├── generateManifest.js  Regenerate data/manifest.json
    ├── markdownParser.js    Markdown rendering helpers
    └── syntaxHighlight.js   Code highlighting helpers
```

## Regenerating the manifest

After adding new files to `content/`, run:

```bash
node scripts/generateManifest.js
```

This scans `content/` recursively and rewrites `data/manifest.json`.

## Adding content

1. Drop a `.cpp` or `.md` file anywhere under `content/`.
2. Run `node scripts/generateManifest.js`.
3. Refresh the browser — the new file appears in the sidebar automatically.
