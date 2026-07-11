# Q3 Intuition - Minimum Length of Anagram Concatenation

The answer must be a divisor of n.

For a candidate length len:
- Take frequency of first block s[0...len-1].
- Every other block of length len must have the same frequency.
- If all match, len is valid.

Try divisors from small to large and return first valid len.
