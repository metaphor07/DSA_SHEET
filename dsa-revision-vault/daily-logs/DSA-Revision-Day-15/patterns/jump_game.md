# Pattern: Jump Game

```text
maxReach = farthest index reachable so far
```

Rule:
```text
if i > maxReach:
    return false

maxReach = max(maxReach, i + nums[i])
```

Memory hook:
```text
If current index is reachable, update farthest reach.
```
