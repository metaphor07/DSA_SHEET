# Booth Algorithm Notes

Booth algorithm finds the starting index of the lexicographically smallest rotation in O(n).

Idea:
Compare two candidate starts i and j inside s+s.

If rotation starting at i is larger, discard i.
If rotation starting at j is larger, discard j.

Finally min(i, j) is the best rotation start.

For this problem, apply Booth separately on:
1. even-index string
2. odd-index string
