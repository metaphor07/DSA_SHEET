# Mistake Notebook - Day 09

## LC 133 - Clone Graph
**Status:** Yellow  
**Pattern:** DFS/BFS + HashMap

### Memory hook
```text
Already cloned? Return clone.
Not cloned? Create clone, then clone neighbors.
```

---

## LC 57 - Insert Interval
**Status:** Yellow  
**Pattern:** Intervals, three-phase merge

### Memory hook
```text
Before overlap -> merge overlap -> after overlap.
```

---

## LC 994 - Rotting Oranges
**Status:** Green  
**Pattern:** Multi-source BFS

### Memory hook
```text
All rotten oranges start together.
Each BFS level is one minute.
```

---

## LC 207 - Course Schedule
**Status:** Green  
**Pattern:** Topological sort using indegree

### Memory hook
```text
[a,b] means b -> a.
Indegree 0 course can be taken.
If completed == numCourses, no cycle.
```
