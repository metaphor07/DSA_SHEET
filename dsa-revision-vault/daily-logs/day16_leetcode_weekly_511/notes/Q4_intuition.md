# Q4 Intuition - Minimum Number of String Groups

For a word s:

E = characters at even indices
O = characters at odd indices

The operation:
- cyclically shift E by any amount
- cyclically shift O by any amount
- rebuild word

So two words are equivalent iff:
1. E1 is a cyclic rotation of E2
2. O1 is a cyclic rotation of O2

To group strings, convert each word into a canonical key:

canonical(E) + "#" + canonical(O)

canonical(x) = lexicographically smallest cyclic rotation of x.

Then answer = number of unique keys.
