# Q4 Intuition - Minimum Weighted Subgraph With Required Paths

For each query:
src1, src2, dest

We need the minimum subtree that allows:
src1 -> dest
src2 -> dest

In a tree, the minimum subtree connecting three nodes is the union of paths between them.

For three nodes a, b, c:

answer = (dist(a,b) + dist(a,c) + dist(b,c)) / 2

Why divide by 2?
Every edge in the required union is counted exactly twice among the three pairwise distances.

So the whole problem becomes:
Answer weighted tree distance queries quickly.

Use:
- DFS from root to compute rootDist and depth
- Binary lifting LCA
- dist(u,v) = rootDist[u] + rootDist[v] - 2*rootDist[lca(u,v)]
