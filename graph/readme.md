# Graph

## Important Terms & Definitions

| Term                           | Definition                                                                                                              |
| ------------------------------ | ----------------------------------------------------------------------------------------------------------------------- |
| **Graph**                      | A structure that consists of nodes and edges. `n` = number of nodes, `m` = number of edges.                             |
| **Node (Vertex)**              | A point/element in the graph, numbered using integers 1, 2, ..., n.                                                     |
| **Edge**                       | A connection between two nodes.                                                                                         |
| **Path**                       | A sequence that leads from node `a` to node `b` through edges of the graph.                                             |
| **Length of a path**           | The number of edges in the path. In a weighted graph, it is the sum of edge weights on the path.                        |
| **Cycle**                      | A path in which the first and last nodes are the same.                                                                  |
| **Simple path**                | A path in which each node appears at most once.                                                                         |
| **Connected graph**            | A graph in which there is a path between any two nodes.                                                                 |
| **Component**                  | A connected part of a graph. A disconnected graph has multiple components.                                              |
| **Tree**                       | A connected graph that consists of `n` nodes and `n − 1` edges. There is a unique path between any two nodes.           |
| **Directed graph**             | A graph in which edges can be traversed in one direction only.                                                          |
| **Undirected graph**           | A graph in which edges can be traversed in both directions.                                                             |
| **Weighted graph**             | A graph in which each edge is assigned a weight (often interpreted as edge length).                                     |
| **Shortest path**              | The path between two nodes with the minimum total length (sum of edge weights).                                         |
| **Neighbors / Adjacent nodes** | Two nodes that have an edge between them.                                                                               |
| **Degree**                     | The number of neighbors of a node. The sum of degrees in a graph is always `2m` (always even).                          |
| **Regular graph**              | A graph where the degree of every node is a constant `d`.                                                               |
| **Complete graph**             | A graph where the degree of every node is `n − 1`, i.e., it contains all possible edges between nodes.                  |
| **Indegree**                   | In a directed graph, the number of edges that end at the node.                                                          |
| **Outdegree**                  | In a directed graph, the number of edges that start at the node.                                                        |
| **Coloring**                   | An assignment of colors to nodes such that no two adjacent nodes share the same color.                                  |
| **Bipartite graph**            | A graph that can be colored using only two colors. A graph is bipartite if and only if it contains no odd-length cycle. |
| **Simple graph**               | A graph with no self-loops and no multiple edges between two nodes.                                                     |

## Graph Representations

| Representation       | Description                                                                                                                                                        |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Adjacency list**   | Each node `x` is assigned a list of nodes to which there is an edge from `x`. Most popular representation. For weighted graphs, stores `(neighbor, weight)` pairs. |
| **Adjacency matrix** | A 2D array where `matrix[u][v]` indicates whether an edge exists between `u` and `v`.                                                                              |
| **Edge list**        | A list of all edges in the graph, where each edge is represented as `(u, v)` or `(u, v, weight)`.                                                                  |

# Topics & Algorithms

## Tier 1 — Must Know

| Algorithm                      | Description                                                                                                                                              |
| ------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **DFS** (Depth-First Search)   | Traverses a graph by going as deep as possible before backtracking. Implemented with recursion or a stack. Foundation for countless problems.            |
| **BFS** (Breadth-First Search) | Traverses a graph level by level using a queue. Finds shortest path in unweighted graphs.                                                                |
| **Connected Components**       | Counting/identifying disconnected pieces of a graph via DFS/BFS. Classic island/region problems.                                                         |
| **Cycle Detection**            | Detecting cycles in directed or undirected graphs using DFS coloring or Union-Find.                                                                      |
| **Topological Sorting**        | Linear ordering of nodes in a DAG such that for every edge `u→v`, `u` comes before `v`. Used in course scheduling, build systems, dependency resolution. |
| **Dijkstra's Algorithm**       | Finds shortest paths from a source to all nodes with non-negative edge weights. Uses a min-priority queue. `O((n+m) log n)`.                             |
| **Union-Find** (DSU)           | Tracks connected components with near-`O(1)` union and find operations (with path compression + union by rank/size).                                     |

## Tier 2 — Very Common

| Algorithm                        | Description                                                                                                                      |
| -------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- |
| **Bipartite Check / 2-Coloring** | Test whether a graph can be colored with 2 colors (no odd-length cycle). Done via BFS/DFS coloring.                              |
| **Bellman–Ford Algorithm**       | Finds shortest paths from a source even with negative edge weights. Also detects negative cycles. `O(n·m)`.                      |
| **Kruskal's Algorithm**          | Minimum Spanning Tree by greedily adding the smallest edges that don't form a cycle (uses Union-Find).                           |
| **Prim's Algorithm**             | Minimum Spanning Tree by growing a tree from a starting node, always adding the smallest edge connecting the tree to a new node. |
| **Tree Traversal**               | DFS-based traversal of trees; computing subtree information bottom-up (subtree size, sum, etc.).                                 |
| **Tree Diameter**                | The longest path between any two nodes in a tree. Computed via two DFS/BFS passes or one DFS with subtree depths.                |
| **DP on DAG**                    | Dynamic programming over a DAG using topological order (longest path, number of paths, shortest path in DAG).                    |

## Tier 3 — Useful

| Algorithm                                      | Description                                                                                                                         |
| ---------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| **Floyd–Warshall Algorithm**                   | All-pairs shortest paths via DP. `O(n³)`. Good when graph is small/dense.                                                           |
| **Lowest Common Ancestor (LCA)**               | Finding the deepest common ancestor of two tree nodes. Solved via binary lifting (sparse table) or Euler tour + RMQ.                |
| **Binary Lifting / k-th Ancestor**             | Preprocessing ancestors at powers of 2 for fast jump-up queries on trees.                                                           |
| **Strongly Connected Components** (Kosaraju's) | Decompose a directed graph into maximal SCCs using two DFS passes (one on the reverse graph).                                       |
| **Successor Paths** (Functional Graphs)        | Every node has exactly one outgoing edge — find the k-th successor via binary lifting; detect cycles via Floyd's tortoise-and-hare. |
| **Subtree Queries / Euler Tour**               | Flatten a tree into an array using DFS entry/exit times, enabling range queries on subtrees with segment/Fenwick trees.             |
| **All Longest Paths in a Tree**                | For each node, find the longest path starting from it. Re-rooting technique.                                                        |

## Tier 4 — Niche

| Algorithm                      | Description                                                                                                                          |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------ |
| **2SAT Problem**               | Solving 2-satisfiability boolean formulas by building an implication graph and finding SCCs.                                         |
| **Ford–Fulkerson Algorithm**   | Computes maximum flow in a flow network by repeatedly finding augmenting paths in the residual graph.                                |
| **Maximum Bipartite Matching** | Maximum number of disjoint pairings between two sets, solved via max-flow reduction.                                                 |
| **Disjoint Paths / Min Cut**   | Maximum number of edge-disjoint paths from source to sink equals max flow (max-flow min-cut theorem).                                |
| **Path Covers**                | Minimum number of paths needed to cover all nodes of a DAG; reduces to bipartite matching.                                           |
| **Eulerian Paths/Circuits**    | A path/circuit that visits every edge exactly once. Exists iff degrees satisfy specific parity conditions (Hierholzer's algorithm).  |
| **Hamiltonian Paths/Circuits** | A path/circuit that visits every node exactly once. NP-hard in general; solvable via bitmask DP for small `n`.                       |
| **De Bruijn Sequences**        | Shortest string containing every length-`n` string over an alphabet as a substring. Built via Eulerian circuit on a De Bruijn graph. |
| **Knight's Tours**             | Path on a chessboard where a knight visits every square exactly once. Solved with backtracking + Warnsdorff's heuristic.             |
| **Offline Tree Algorithms**    | Processing many tree queries together (e.g., offline LCA via Tarjan's algorithm using Union-Find).                                   |
