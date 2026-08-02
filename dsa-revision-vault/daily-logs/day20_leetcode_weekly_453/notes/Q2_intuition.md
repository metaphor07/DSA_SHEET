# Q2 Intuition - Count Computer Unlocking Permutations

Computer 0 is already unlocked.

To unlock computer i, we need already unlocked j where:

j < i and complexity[j] < complexity[i]

Since 0 < i for every i > 0, computer 0 can unlock everyone if:

complexity[0] < complexity[i] for all i > 0

So complexity[0] must be the unique minimum.

If this condition fails:
answer = 0

If it holds:
all remaining n-1 computers can be unlocked in any order.

answer = (n-1)!
