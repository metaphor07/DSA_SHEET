# Critics Special

Brute force:
For each V, mark V and all neighbours, then scan all nodes to find maximum popularity uninspected node.
This is O(N^2).

Intuition:
Popularity ratings are distinct.
Sort nodes by popularity descending once.
For each V, the answer is the first node in this sorted list that is not V and not a neighbour of V.

Optimal:
Use timestamp marking.
For each V:
1. mark V
2. mark all neighbours
3. scan sorted candidates until first unmarked node

In a tree, each node only blocks degree(V)+1 nodes, so the scan is efficient.

Complexity:
O(N log N + total skipped nodes)
