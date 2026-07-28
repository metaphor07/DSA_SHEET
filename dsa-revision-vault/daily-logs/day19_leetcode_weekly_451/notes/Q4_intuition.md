# Q4 Intuition - Lexicographically Smallest String After Adjacent Removals

This is harder than Q2 because we need the lexicographically smallest possible result, not just one greedy final result.

Removing one substring can make far-away characters become adjacent.

So first compute:

can[l][r] = true if s[l...r] can be fully removed.

A substring can be fully removed by:
1. Removing the inside first, then removing endpoints if endpoints are consecutive.
2. Splitting it into two removable parts.

Then define:

dp[i] = lexicographically smallest string obtainable from suffix s[i...n-1].

Choices:
1. Keep s[i]:
   s[i] + dp[i+1]

2. Delete a removable prefix s[i...j]:
   dp[j+1]

Take minimum among all choices.
