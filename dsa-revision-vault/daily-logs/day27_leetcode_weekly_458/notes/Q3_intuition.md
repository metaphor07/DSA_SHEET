# Q3 Intuition - Process String with Special Operations II

Direct simulation works only for small output strings.

Problem:
# duplicates the whole string, so result can become huge.

Need only kth character.

Use two passes.

Pass 1:
Calculate final length only.

Pass 2:
Go backward and map index k.

Reverse rules:
- letter c: if k == len - 1, answer c, else len--
- *: backward restores one removed char, so len++
- #: old length = len / 2, so k = k % oldLength
- %: reverse maps k to len - 1 - k
