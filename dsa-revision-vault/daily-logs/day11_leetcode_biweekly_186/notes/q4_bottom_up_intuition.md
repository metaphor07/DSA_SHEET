# Q4 Bottom-Up DP Intuition

dp[i][j] means:

Number of ways after forming a prefix of target,
where the last chosen index in word1 is i,
and the last chosen index in word2 is j.

Use shifted indices:
0 means no character chosen yet.
1 means index 0 was chosen.
2 means index 1 was chosen.

For each target character:
- choose from word1 using prefix sums over previous word1 indices
- choose from word2 using prefix sums over previous word2 indices

Final answer:
sum dp[i][j] where i > 0 and j > 0,
because both strings must be used at least once.
