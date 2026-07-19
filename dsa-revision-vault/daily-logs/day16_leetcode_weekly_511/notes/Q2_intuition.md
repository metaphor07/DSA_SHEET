# Q2 Intuition - Even Number of Knight Moves

A chessboard square color is determined by:

(x + y) % 2

A knight move always changes color.

So:
- odd moves => opposite color
- even moves => same color

Therefore answer is true iff start and target have the same color.
