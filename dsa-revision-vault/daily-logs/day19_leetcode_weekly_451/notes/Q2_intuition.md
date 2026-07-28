# Q2 Intuition - Resulting String After Adjacent Removals

When you repeatedly remove adjacent consecutive letters, a removal can create a new pair.

Example:
s = "adcb"

Process with stack:
a -> "a"
d -> "ad"
c -> d and c are consecutive, remove d -> "a"
b -> a and b are consecutive, remove a -> ""

Answer = ""

Why not erase in a loop?
- erase shifts characters
- loop may skip newly adjacent pairs
- erase is O(n), causing O(n^2)

Pattern:
Repeated adjacent deletion = stack.
