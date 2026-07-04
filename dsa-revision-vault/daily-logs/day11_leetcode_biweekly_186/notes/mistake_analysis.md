# Biweekly 186 Mistake Analysis

## Q3

The recursion structure was correct after fixing:
- size check should use parameters a and b
- curBit should be compared with 0, not '0'

## Q4

This is a hard DP problem.

Main missing trigger:
Two independent strictly increasing index sequences.

That means we must remember:
- last used index in word1
- last used index in word2
- whether both strings were used
