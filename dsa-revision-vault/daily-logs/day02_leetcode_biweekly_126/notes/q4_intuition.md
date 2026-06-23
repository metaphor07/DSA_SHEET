# Q4 Intuition

Your original code:

not_pick + pick

counts subsequences with sum k.

But the power contribution counts how many larger subsequences can contain each valid target subsequence.

For a target subsequence T:
remaining elements = n - len(T)
contribution = 2^(n - len(T))

During DP:
- Pick current element in target: one choice.
- Do not pick current element in target: it can still be included or excluded in larger subsequence, so two choices.

Therefore:

rec(ind, k) = 2 * rec(ind + 1, k) + rec(ind + 1, k - nums[ind])
