# Q4 Intuition - Minimum Cost to Equalize Array

Operations:
1. cost1: increase one element by 1.
2. cost2: increase two different elements by 1.

For a fixed target T:
need[i] = T - nums[i]

Let:
total = sum of all needs
maxNeed = maximum need of one element

A pair operation consumes 2 increments, but from two different elements.

Maximum pair operations:
min(total / 2, total - maxNeed)

Why total - maxNeed?
The largest deficit needs other elements as partners. It cannot pair with itself.

Remaining increments are singles:
singles = total - 2 * pairs

Cost:
pairs * cost2 + singles * cost1

If 2 * cost1 <= cost2:
Pair operation is not useful.
Use only singles to reach max(nums).

Why target can be greater than max:
Sometimes making the already-large elements even larger creates enough partner deficits to use cheap pair operations.
