# Pattern: Intervals

## Merge Intervals
Sort by start. Compare current interval with last merged interval.

```text
if current.start <= last.end:
    merge
else:
    push current
```

## Insert Interval
Three phases:

```text
1. Add intervals before newInterval.
2. Merge all overlapping intervals.
3. Add intervals after newInterval.
```

## Non-overlapping Intervals
Sort by end time. Keep intervals ending earliest.
