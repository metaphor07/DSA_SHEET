# Q4 Intuition - Count Distinct Ways to Form Target

We form target from left to right.

For each character of target, choose a matching character from either:
- word1
- word2

But chosen indices from word1 must be strictly increasing.
Chosen indices from word2 must also be strictly increasing.

Also, at least one character must be chosen from both strings.

Recursive state:
rec(pos, last1, last2, mask)

pos:
current index in target

last1:
last chosen index in word1

last2:
last chosen index in word2

mask:
which strings have been used:
0 = none
1 = word1
2 = word2
3 = both

At the end, return 1 only if mask == 3.
