# Q3 Recursion + Memoization

Recursive state:

solve(col, prevDigit)

Meaning:
minimum operations from column col to the last column,
where previous column used prevDigit.

Try every digit from 0 to 9 for current column.

Skip digit if digit == prevDigit.

Answer:

cost[col][digit] + solve(col + 1, digit)

Because the first column has no previous digit:

solve(0, -1)

To store prevDigit = -1 in dp, use prevDigit + 1.
