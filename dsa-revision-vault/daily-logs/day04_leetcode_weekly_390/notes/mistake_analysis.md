# Day 4 Mistake Analysis

## Q2

Mistake:
Thinking answer is based on nearest power of 2.

Correct:
Choose x, increase 1 to x, then duplicate x.

Formula:
(x - 1) + (ceil(k / x) - 1)

## Q3

Your max heap idea was correct.

Missing detail:
When frequencies change, old heap entries become invalid.
Use lazy deletion with hashmap.

## Q4

Missing trigger:
Many suffix queries require a trie on reversed strings.

Important implementation detail:
Each trie node stores the best answer index for that suffix prefix path.
