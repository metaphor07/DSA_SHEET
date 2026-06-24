# Q3 Intuition

Problem:
Make the string k-special, meaning the difference between any two positive character frequencies is at most k.

Suppose the minimum final positive frequency is base.

Then every kept character must have frequency in:

[base, base + k]

For each original frequency f:
- f < base: delete all f characters
- base <= f <= base + k: keep as it is
- f > base + k: delete f - (base + k)

Try each existing frequency as base and take minimum deletions.

Pattern:
frequency difference constraint + deletion = enumerate allowed frequency window.
