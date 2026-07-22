# Mistake Notebook - Day 18

## Overall Graph Status
**Status:** Yellow for all graph questions.

### Reason
Graph pattern identification was okay, but implementation needs more repetition.

---

## LC 547 - Number of Provinces
**Status:** Yellow  
**Pattern:** DFS/BFS connected components

### Mistakes
```text
adj list size was missing.
visited was not marked.
queue used back() instead of front().
```

### Memory hook
```text
Each unvisited city starts one DFS/BFS.
Number of starts = number of provinces.
```

---

## LC 684 - Redundant Connection
**Status:** Yellow  
**Pattern:** Union Find

### Memory hook
```text
If two nodes already have same parent, this edge creates a cycle.
```

---

## LC 721 - Accounts Merge
**Status:** Yellow  
**Pattern:** Union Find + HashMap grouping

### Memory hook
```text
Emails are nodes.
Emails in same account must be unioned.
Group emails by ultimate parent.
```

---

## LC 210 - Course Schedule II
**Status:** Yellow  
**Pattern:** Topological Sort

### Memory hook
```text
[a, b] means b -> a.
Indegree 0 = course with no remaining prerequisite.
```

---

## LC 743 - Network Delay Time
**Status:** Yellow  
**Pattern:** Dijkstra

### Memory hook
```text
Always expand currently closest node.
dist[node] = shortest time to reach node.
```

---

## LC 787 - Cheapest Flights Within K Stops
**Status:** Yellow  
**Pattern:** BFS by stops / modified shortest path

### Memory hook
```text
Same node can be reached with different stops.
Stops must be part of the state.
```

---

## LC 1584 - Min Cost to Connect All Points
**Status:** Yellow  
**Pattern:** MST / Prim

### Memory hook
```text
Keep adding the cheapest point not yet connected.
Distance = Manhattan distance.
```
