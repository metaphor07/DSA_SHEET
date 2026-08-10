# Q2 Intuition - Power Grid Maintenance

Use DSU to find connected components.

DSU only tells the component identity. It does not tell the smallest online node.

So maintain:
componentRoot -> set of currently online nodes

For query type 1 node:
- if node exists in its component set, return node
- otherwise return smallest element in that component set
- if set is empty, return -1

For query type 2 node:
- erase node from its component set

No separate active array is required because set membership tells whether a node is online.
