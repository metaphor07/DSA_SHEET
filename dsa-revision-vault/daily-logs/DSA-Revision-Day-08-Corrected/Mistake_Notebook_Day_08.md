# Mistake Notebook - Day 08 Corrected

## LC 200 - Number of Islands
**Status:** Green  
**Pattern:** Grid DFS / flood fill

### Correct idea
When land is found:
1. Count one island.
2. Sink the full island using DFS.
3. Continue scanning.

### Memory hook
```text
Find land -> count island -> sink full island.
```

---

## LC 695 - Max Area of Island
**Status:** Green  
**Pattern:** Grid DFS returning area

### Correct idea
Same as Number of Islands, but DFS returns area.

### Memory hook
```text
DFS should return 1 + area of all connected land cells.
```

---

## LC 994 - Rotting Oranges
**Status:** Red  
**Pattern:** Multi-source BFS

### Mistake
I tried DFS from each fresh orange to find the nearest rotten orange.

That is the wrong direction.

### Correct intuition
All rotten oranges spread together level by level.

### Memory hook
```text
Rotting Oranges = multi-source BFS.
All rotten oranges start together.
Each BFS level = one minute.
```

---

## LC 133 - Clone Graph
**Status:** Red  
**Pattern:** DFS/BFS + HashMap

### Correct intuition
Use a map:

```text
old node -> cloned node
```

This prevents infinite recursion in cyclic graphs.

### Memory hook
```text
Already cloned? Return clone.
Not cloned? Create clone, then clone neighbors.
```

---

## LC 207 - Course Schedule
**Status:** Red  
**Pattern:** Topological sort / indegree BFS

### Correct intuition
For prerequisite `[a, b]`:

```text
b -> a
```

Course `a` depends on course `b`.

### Memory hook
```text
Course with indegree 0 can be taken.
If all courses are taken, return true.
Otherwise cycle exists.
```
