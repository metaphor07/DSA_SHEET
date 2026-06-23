# Q3 Intuition

The value increases when repeated characters increase.

For a '?', placing a character with current frequency `cnt` adds `cnt` to the value.
So choose the character with minimum frequency.

Tie: choose lexicographically smaller character.

Important:
Do not fill immediately for lexicographic answer.
First collect selected characters, sort them, then fill '?' from left to right.
