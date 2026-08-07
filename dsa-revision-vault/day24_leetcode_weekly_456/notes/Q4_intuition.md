# Q4 Intuition - Maximize Spanning Tree Stability with Upgrades

This is a maximize minimum problem.

So binary search the answer X.

For a fixed X:
Every edge in the selected spanning tree must have final strength >= X.

Mandatory edge:
- must be included
- cannot be upgraded
- if strength < X, impossible
- if mandatory edges form a cycle, impossible

Optional edge:
- if strength >= X, usable for free
- else if 2 * strength >= X, usable using one upgrade
- otherwise unusable

Use DSU:
1. Add mandatory edges.
2. Add optional free edges.
3. Add optional upgraded edges while upgrades remain.
4. If all nodes become connected, X is possible.
