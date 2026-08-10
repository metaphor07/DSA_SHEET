# Q2 Intuition - Minimize Maximum Component Cost

Your first greedy thought may be:
remove the maximum weight edge first until we get k components.

That is close, but the cleaner implementation is the reverse:

Start with n isolated components.
Add edges from smallest weight to largest.
Stop when components become k.

Why?
To minimize the maximum edge inside any final component, we should only use the smallest possible edges.

This is Kruskal-style DSU.
