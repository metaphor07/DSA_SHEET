# Q3 Intuition - Divisible Game

For fixed k:

nums[i] contributes:
+nums[i] if nums[i] is divisible by k
-nums[i] otherwise

So for fixed k, answer is maximum subarray sum of this transformed array.

But trying every k and building full arrays is too slow.

Observation:
Only k values that divide at least one nums[i] can create positive positions.

So:
1. For every nums[i], enumerate divisors > 1.
2. Store indices for each divisor k.
3. For each k, run compressed Kadane:
   - positive positions are stored
   - gaps between them are negative sums
   - use prefix sum to calculate gap cost quickly

Tie rule:
If two k values give same maximum score difference, choose smaller k.
