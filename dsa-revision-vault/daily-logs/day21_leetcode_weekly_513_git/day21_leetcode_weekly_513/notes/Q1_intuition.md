# Q1 Intuition - Maximize Pair Strength Using GCD

Strength of pair (x, y):

(x * y) / gcd(x, y)^2

Let g = gcd(x, y).

Then:
strength = (x / g) * (y / g)

This avoids overflow better than multiplying x*y first.

Since Q1 constraints are small enough, try every pair.
