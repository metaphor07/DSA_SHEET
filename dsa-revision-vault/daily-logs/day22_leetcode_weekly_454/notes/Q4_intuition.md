# Q4 Intuition - Find Weighted Median Node in Tree

For query (u, v), need first node x on path u -> v such that:

distance(u, x) >= half of distance(u, v)

Because edge weights are integers:

need = ceil(totalDistance / 2)
     = (totalDistance + 1) / 2

Split path using LCA:

u -> lca -> v

If need is within u -> lca:
climb upward from u using binary lifting.

Otherwise:
median lies on lca -> v.
Find it by jumping upward from v while candidate still has enough distance from lca.

Distance formula:
dist(a, b) = rootDist[a] + rootDist[b] - 2 * rootDist[lca(a, b)]
