# Q2 Intuition - Maximum Value of an Alternating Sequence

This is not DP.

We need:
- seq[0] = s
- adjacent difference at most m
- strictly alternating

To maximize the largest element, the best shape is:

s < peak > valley < bigger_peak > valley ...

First peak:
s + m

After peak P, the next element must be less than P.
To keep the next peak as large as possible, choose valley = P - 1.

Then next peak:
(P - 1) + m = P + m - 1

So every next peak increases by m - 1.

Number of peak positions in n elements:
n / 2

Formula:
if n == 1: answer = s
else answer = s + m + (n/2 - 1) * (m - 1)
