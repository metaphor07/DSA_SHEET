# Q2 Intuition - K Periodic Word

The word is split into blocks of size k.

One operation can change one full block into another block.

To make the whole word k-periodic, all blocks must become equal.

So:
- Count frequency of each k-length block.
- Keep the most frequent block.
- Change all other blocks.

Answer = totalBlocks - maxFrequency.
