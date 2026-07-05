# Q2 Intuition - Subsequence After One Replacement

A simple greedy replacement at the first mismatch is wrong.

Counterexample:

s = "ws"
t = "xwxt"

Wrong greedy:
replace w -> x at t[0], then cannot match s.

Correct:
replace s[1] = 's' with 'x'.
Then "wx" is a subsequence of "xwxt".

Correct idea:
At most one replacement means one position of s can behave like a wildcard.

For every replacement position p:
- s[0...p-1] must match before the wildcard
- s[p+1...n-1] must match after the wildcard

Replacement at p is possible if:

left[p] < right[p + 1]
