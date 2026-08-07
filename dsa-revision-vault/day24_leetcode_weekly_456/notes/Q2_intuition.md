# Q2 Intuition - Longest Common Prefix After Removals

Precompute adjacent LCP values:

pairLCP[i] = LCP(words[i], words[i + 1])

When removing index i, only local adjacency changes:
- pair (i - 1, i) disappears
- pair (i, i + 1) disappears
- pair (i - 1, i + 1) appears

All other adjacent pairs remain unchanged.

So maintain current adjacent LCP values in a multiset.

For each removal:
1. remove affected old pairs
2. add new pair
3. answer is maximum value in multiset
4. rollback
