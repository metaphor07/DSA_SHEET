# Q4 Brute Force to Optimal

## Brute force

Try every simple path.
For each path, check if labels form palindrome.

Problem:
Number of simple paths is exponential.

## Improved thought

A palindrome can be built from the center outward.

Middle can be:
- one node for odd length
- two adjacent same-label nodes for even length

Then expand both endpoints with same labels.

## Optimal

Use bitmask DP:

dp[mask][left][right]

Meaning:
A palindromic path exists using nodes in mask with endpoints left and right.

Expansion:
newLeft is neighbor of left
newRight is neighbor of right
newLeft and newRight are unused
label[newLeft] == label[newRight]

n <= 14 is the trigger for bitmask DP.
