# Pattern: Hand of Straights

## Core idea
Use ordered map.

Always start from the smallest remaining card.

For each smallest card x:
```text
try to form x, x+1, x+2, ..., x+groupSize-1
```

## Memory hook
Always build group from smallest remaining card.
