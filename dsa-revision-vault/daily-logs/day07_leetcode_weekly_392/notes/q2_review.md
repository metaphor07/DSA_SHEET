# Q2 Review

Your direction was mostly correct.

Main correction:
Cost to convert character c to 'a' in cyclic alphabet is:

min(c - 'a', 'z' - c + 1)

Greedy rule:
Process left to right and make each character as small as possible.
