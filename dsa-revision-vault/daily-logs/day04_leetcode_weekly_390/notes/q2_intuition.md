# Q2 Intuition

The sample k = 11 gives answer 5, but not because of nearest power of 2.

Choose a final base value x.

Starting from [1]:
- Increase 1 to x. Cost = x - 1.
- Duplicate x until total sum >= k.

If we need copies of x:

copies = ceil(k / x)

Duplicate operations = copies - 1.

Total operations:

(x - 1) + (ceil(k / x) - 1)

Try all x from 1 to k and take minimum.
