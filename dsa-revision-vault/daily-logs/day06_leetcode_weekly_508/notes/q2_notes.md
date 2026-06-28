# Q2 Notes - Filter Occupied Intervals

Your main direction was close:
- merge the occupied intervals first
- then remove the free interval

The only unnecessary part was trying to insert `[freeStart, freeEnd]` into occupied intervals.
That should not be done.

Correct flow:
1. Sort occupied intervals.
2. Merge intervals that overlap or touch.
3. For each merged interval:
   - if no overlap with free interval, keep it
   - otherwise keep left part `[l, freeStart - 1]` if valid
   - and/or right part `[freeEnd + 1, r]` if valid
