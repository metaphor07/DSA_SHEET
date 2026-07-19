# Day 16 Mistake Analysis

## Q1

Your original DFS idea was correct.
Only bug risk:
null should return INT_MIN, not 0.

## Q2

No BFS needed.
Even knight move means same color.

## Q3

Your idea was close:
count zeros and check zero positions/prefixes.

Bug:
You counted all '?' in prefix as possible zeros.
But only a limited number of '?' can become zero globally.

Fix:
curZero + min(curQuestion, needQuestionAsZero)

## Q4

Main observation:
The transformation does not mix even and odd index characters.
It only rotates them independently.

So normalize even part and odd part separately.
