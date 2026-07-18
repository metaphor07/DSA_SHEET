# Q4 Intuition - Minimum Cost to Convert String III

Important constraint:
Once a character position is used in a rule application, it cannot be used again.

That means chosen rule intervals cannot overlap.

So this becomes prefix DP:

dp[i] = minimum cost to convert source prefix of length i to target prefix of length i.

At index i:

Option 1:
If source[i] == target[i], leave it unchanged:
dp[i+1] = min(dp[i+1], dp[i])

Option 2:
Try every rule at i.
A rule can be applied if:
- i + len <= n
- replacement == target substring
- pattern matches source substring
- '*' in pattern can match any source character

Cost:
base cost + number of stars in pattern.

Then:
dp[i+len] = min(dp[i+len], dp[i] + cost)

Complexity:
n <= 5000
rules <= 200
len <= 20

O(n * rules * len) = about 20 million checks.
