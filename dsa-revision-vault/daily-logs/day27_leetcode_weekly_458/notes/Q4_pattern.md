# Q4 Pattern

Important triggers:

n <= 14
graph path
visit each node at most once
maximize path length

This suggests:
bitmask DP

Palindrome condition suggests:
expand matching characters from both ends

Final state:
dp[mask][left][right]
