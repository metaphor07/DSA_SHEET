# Day 3 Mistake Analysis

## Q1

Your logic was correct, but string construction was wrong.

Wrong:
temp += s[i] + s[i + 1];

This adds ASCII values instead of creating a two-character string.

Correct:
string curr = "";
curr += s[i];
curr += s[i + 1];

Better approach:
Use a 26 x 26 boolean matrix and check whether the reverse pair was seen.

## Q2

Solved optimally.

If c appears m times:
answer = m * (m + 1) / 2

Your incremental version also does the same.

## Q3

The missing observation:
Only frequencies matter.

A valid final string must have all positive frequencies inside some range:

[base, base + k]

For every possible base:
- if frequency < base, delete the character fully
- if frequency > base + k, trim it
- otherwise keep it

## Q4

The missing trigger:
binary array + adjacent movement + choose k ones = positions of ones + median.

For chosen existing ones, the best meeting point is the median.
Use prefix sums on positions to calculate movement cost quickly.
