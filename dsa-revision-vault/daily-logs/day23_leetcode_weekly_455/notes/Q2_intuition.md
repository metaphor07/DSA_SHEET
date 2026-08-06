# Q2 Intuition - Inverse Coin Change

Normal Coin Change 2 DP:

dp[0] = 1

for coin in coins:
    for sum from coin to n:
        dp[sum] += dp[sum - coin]

Here coins are unknown.

Build coins from smallest amount to largest amount.

At amount x:
- all smaller coins are already decided
- larger coins cannot affect amount x

So compare current dp[x] with required numWays[x - 1].

Cases:
1. dp[x] == target
   Coin x is not needed.

2. dp[x] + 1 == target
   Coin x must exist.
   It adds exactly one new way to make x: [x].

3. Otherwise
   Impossible.

Pattern:
Inverse DP reconstruction.
