#!/usr/bin/env node
// Run from cp-site/: node scripts/generateManifest.js

const fs = require('fs');
const path = require('path');

const CONTENT_DIR = path.join(__dirname, '..', 'content');
const OUT_FILE = path.join(__dirname, '..', 'data', 'manifest.json');

const TAG_MAP = {
  'algorithms': ['algorithm'],
  'arrays': ['array'],
  'strings': ['string'],
  'sorting': ['sorting'],
  'dynamic-programming': ['dp'],
  'lis': ['dp', 'lis'],
  'lcs': ['dp', 'lcs'],
  'knapsack': ['dp', 'knapsack'],
  'graph': ['graph'],
  'traversal': ['graph', 'bfs', 'dfs'],
  'shortest-path': ['graph', 'shortest-path'],
  'mst': ['graph', 'mst'],
  'representation': ['graph'],
  'trees': ['tree'],
  'number-theory': ['number-theory', 'math'],
  'cpp': ['cpp', 'cpp-stl'],
  'sql': ['sql'],
  'problems': ['problems'],
  'guess_the_output': ['cpp', 'tricky'],
};

function titleFromFile(name) {
  return name
    .replace(/\.[^.]+$/, '')
    .replace(/[_-]/g, ' ')
    .replace(/\b\w/g, c => c.toUpperCase());
}

function tagsFromParts(parts) {
  const tags = new Set();
  for (const p of parts) {
    (TAG_MAP[p] || []).forEach(t => tags.add(t));
  }
  return [...tags];
}

function walk(dir, base = '') {
  const entries = [];
  for (const name of fs.readdirSync(dir).sort()) {
    const full = path.join(dir, name);
    const rel = base ? `${base}/${name}` : name;
    const stat = fs.statSync(full);
    if (stat.isDirectory()) {
      entries.push(...walk(full, rel));
    } else {
      const parts = rel.split('/');
      const category = parts[0];
      const id = rel.replace(/\.[^.]+$/, '');
      entries.push({
        id,
        path: `content/${rel}`,
        title: titleFromFile(name),
        category,
        tags: tagsFromParts(parts.slice(0, -1)),
      });
    }
  }
  return entries;
}

const manifest = walk(CONTENT_DIR);
fs.writeFileSync(OUT_FILE, JSON.stringify(manifest, null, 2));
console.log(`Generated ${manifest.length} entries → ${OUT_FILE}`);
