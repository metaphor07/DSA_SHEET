# Disjoint Set Union (DSU / Union-Find)

## Correctness review

Your overall DSU logic was correct, but there was one important type error:

```cpp
bool findUltimateParent(int node)
```

This function returns a node number such as `1`, `4`, or `7`, so its return type
must be `int`:

```cpp
int findUltimateParent(int node)
```

Using `bool` converts every nonzero parent index to `true`, which becomes integer
`1` when assigned or compared. That can silently corrupt the DSU structure.

The corrected code also adds:

- `isConnected(u, v)`
- `getComponentSize(node)`
- A small `main()` test
- Clearer variable names

Do not normally mix `unionByRank` and `unionBySize` in one solution. Both are
valid optimization strategies, but choose one and use it consistently. The
sample uses both only to demonstrate that both functions work.

---

## What DSU stores

For every node, DSU stores a `parent`.

Initially, every node is its own separate component:

```text
parent[1] = 1
parent[2] = 2
parent[3] = 3
```

After merging nodes, several nodes share the same ultimate parent, also called
the representative or root.

Two nodes belong to the same connected component when:

```cpp
findUltimateParent(u) == findUltimateParent(v)
```

---

## Find with path compression

Suppose the parent chain is:

```text
5 -> 4 -> 3 -> 1
```

Calling `findUltimateParent(5)` reaches root `1`. While recursion returns, path
compression changes the structure to:

```text
5 -> 1
4 -> 1
3 -> 1
```

Future find operations become much faster.

```cpp
int findUltimateParent(int node) {
    if (node == parent[node]) {
        return node;
    }

    return parent[node] =
        findUltimateParent(parent[node]);
}
```

---

## Union by rank

`rank` is an estimate of tree height. It is not the number of nodes.

Steps:

1. Find roots of `u` and `v`.
2. Attach the lower-rank root under the higher-rank root.
3. If both ranks are equal, choose either root and increase its rank by one.

Example:

```text
Tree A rank = 1
Tree B rank = 3
```

Attach A below B. The taller tree's rank usually remains unchanged.

When equal-rank trees merge:

```text
rank 2 + rank 2 -> new rank 3
```

Rank increases only when both root ranks are equal.

---

## Union by size

`size[root]` stores the number of nodes in that component.

Steps:

1. Find roots of `u` and `v`.
2. Attach the smaller component below the larger component.
3. Add the smaller size to the larger root's size.

Example:

```text
Component A size = 3
Component B size = 7
```

Attach A below B:

```text
new size of B = 3 + 7 = 10
```

Only the size stored at the current root is meaningful.

---

## Rank versus size

Both prevent the DSU tree from becoming unnecessarily tall.

| Method | Meaning | Update rule |
|---|---|---|
| Union by rank | Approximate tree height | Increase only when equal ranks merge |
| Union by size | Number of component nodes | Add sizes after every successful merge |

In interviews and competitive programming, union by size is often easier to
reason about because it directly gives component sizes.

With path compression plus either rank or size, the amortized complexity is:

```text
O(alpha(N)) per operation
```

`alpha(N)` is the inverse Ackermann function and grows so slowly that it is
effectively constant for practical input sizes.

Space complexity:

```text
O(N)
```

---

## When to use DSU

Use DSU when a problem repeatedly asks you to:

- Merge two groups/components.
- Check whether two nodes are already connected.
- Count connected components after multiple unions.
- Detect whether adding an edge creates a cycle.
- Maintain connectivity while processing edges.
- Group equivalent items.

DSU works especially well for undirected graphs and offline connectivity
problems.

It does not naturally support deleting edges or answering shortest-path
questions.

---

## Common DSU pattern

```cpp
DisjointSet ds(n);

for (auto &edge : edges) {
    int u = edge[0];
    int v = edge[1];

    if (ds.findUltimateParent(u) ==
        ds.findUltimateParent(v)) {
        // u and v were already connected.
        // This edge may form a cycle.
    } else {
        ds.unionBySize(u, v);
    }
}
```

---

## Typical problem categories

### Connected components

- Number of Provinces
- Number of Connected Components in an Undirected Graph
- Friend Circles / social groups
- Network connectivity

### Cycle and redundant-edge detection

- Redundant Connection
- Detect Cycle in an Undirected Graph
- Remove Maximum Number of Edges while preserving connectivity

### Minimum spanning tree

Kruskal's algorithm sorts edges by weight and uses DSU to reject edges that
would create a cycle.

- Kruskal MST
- Min Cost to Connect All Points
- Connecting Cities With Minimum Cost

### Grid and island problems

Treat each cell as a node:

```text
nodeId = row * columns + column
```

- Number of Islands using DSU
- Number of Islands II
- Making a Large Island
- Regions Cut by Slashes
- Most Stones Removed with Same Row or Column

### Grouping and equivalence

- Accounts Merge
- Similar String Groups
- Satisfiability of Equality Equations
- Smallest Equivalent String

### Offline query problems

- Distance Limited Paths Exist
- Process connectivity queries after sorting edges by weight
- Dynamic island additions
