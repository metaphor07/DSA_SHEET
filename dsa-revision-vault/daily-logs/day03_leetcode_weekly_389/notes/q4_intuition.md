# Q4 Intuition

Problem type:
minimum adjacent moves to collect selected 1s.

Key trigger:
For adjacent movement problems, store the positions of important elements.

Example:
nums = [0, 1, 0, 1, 0, 0, 1]
positions of 1s = [1, 3, 6]

If we choose some existing 1s and want to collect them near one place, the minimum sum of distances is achieved at the median.

For positions [1, 3, 6]:
median = 3
cost = |1 - 3| + |3 - 3| + |6 - 3| = 5

So:
1. Store indices of all 1s.
2. Choose a consecutive window of existing 1s.
3. Use median to minimize movement.
4. Use prefix sums to calculate window distance quickly.
5. Add cost for created ones using maxChanges.

Pattern:
binary array + adjacent swaps + pick k = positions + window + median + prefix sum.
