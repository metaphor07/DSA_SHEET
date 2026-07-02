# Pattern: Jump Game II

Think of jumps as BFS levels.

Variables:
```text
currentEnd = end of current jump range
farthest = farthest index reachable from current range
jumps = number of ranges used
```

Rule:
```text
farthest = max(farthest, i + nums[i])

if i == currentEnd:
    jumps++
    currentEnd = farthest
```

Memory hook:
```text
Each time current range ends, take one jump.
```
