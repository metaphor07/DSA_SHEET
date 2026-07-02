# Why Heap Fails for Q3

Heap generation idea:

Generate multiples:
coin 3 -> 3, 6, 9, 12...
coin 6 -> 6, 12, 18...
coin 9 -> 9, 18, 27...

Then remove duplicates and find kth value.

Problem:
If k is huge, this requires generating almost k values.

For k = 1e9, generating one by one is impossible.

Binary search only needs around 40 checks.
Each check counts how many valid numbers are <= mid.
