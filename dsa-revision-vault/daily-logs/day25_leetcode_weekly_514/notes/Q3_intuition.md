# Q3 Intuition

Use Maximal Square DP:

dp[i][j] = largest all-1 square ending at (i, j)

Binary search side length k.

For fixed k, store every valid square's top-left.
Two squares are non-overlapping if one is completely above or completely left of the other.

Use:
- prefixBottom
- prefixRight

Bug to remember:
prefixRight size must be cols, not rows.
