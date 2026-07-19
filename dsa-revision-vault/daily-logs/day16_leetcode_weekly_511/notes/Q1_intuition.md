# Q1 Intuition - Count Dominant Nodes

A node is dominant if:

node value == maximum value in its subtree

Use postorder DFS.

For each node:
1. Get maximum from left subtree.
2. Get maximum from right subtree.
3. If root->val >= max(leftMax, rightMax), count it.
4. Return maximum of root value and child maximum.

Important bug:
For null node, return INT_MIN, not 0.
If node values can be negative, returning 0 gives wrong answer for negative leaves.
