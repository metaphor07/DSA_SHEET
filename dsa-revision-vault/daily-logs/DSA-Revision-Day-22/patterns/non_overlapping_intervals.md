# Pattern: Non-overlapping Intervals

## Correct greedy
Sort by end time.

```text
If interval start < lastEnd:
    remove it
Else:
    keep it and update lastEnd
```

## Memory hook
Earliest ending interval leaves maximum room for future intervals.
