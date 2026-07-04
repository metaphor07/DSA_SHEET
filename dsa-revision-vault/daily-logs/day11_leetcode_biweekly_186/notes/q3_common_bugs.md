# Q3 Common Bugs

Bug 1:
Checking class variables before assigning them.

Wrong:
if (s1.size() != s2.size()) return -1;

Correct:
if (a.size() != b.size()) return -1;

Bug 2:
Comparing integer bit with character.

Wrong:
curBit == '0'

Correct:
curBit == 0

Because curBit is stored as integer 0 or 1.
