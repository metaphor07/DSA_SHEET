# Q3 Intuition - Minimum Increments to Equalize Leaf Paths

Goal:
Make all root-to-leaf path sums equal by increasing node costs.
Need minimum number of nodes increased.

At a node, every child subtree returns its maximum path sum to a leaf.

Example:
child path sums = [10, 7, 10, 4]

The final value must match the maximum:
max = 10

Children with smaller sums need one increment operation:
7 and 4 are smaller, so answer += 2.

Then current node returns:
cost[node] + maxChildPathSum

Why greedy works:
If a child subtree has smaller path sum than the maximum sibling subtree, at least one node in that child side must be increased.
Counting that child once is optimal.
