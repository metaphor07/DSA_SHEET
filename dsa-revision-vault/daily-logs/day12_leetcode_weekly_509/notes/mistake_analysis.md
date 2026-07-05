# Weekly 509 Mistake Analysis

## Q2

The first greedy idea was wrong because using the replacement too early can block a better future match.

Correct pattern:
one replacement = one wildcard position
prefix match + suffix match

## Q3

The important hidden transformation:
fixed k => signed array => max subarray sum

Then optimize over k using divisors.

## Q4

The missing algorithmic tool:
Manacher's algorithm.

This is the standard way to find palindrome ranges around every center in linear time.
