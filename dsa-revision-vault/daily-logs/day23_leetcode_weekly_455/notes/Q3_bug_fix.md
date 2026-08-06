# Q3 Bug Fix

Wrong assumption:
tree[u].push_back(v)

This treats edges as directed parent -> child.

But the problem gives undirected edges.

Failing case:
n = 3
edges = [[1,0],[0,2]]
cost = [2,1,3]

If only u -> v is added:
1 -> 0
0 -> 2

DFS from 0 misses node 1.

Correct construction:
tree[u].push_back(v)
tree[v].push_back(u)

Then DFS uses parent to avoid going back.
