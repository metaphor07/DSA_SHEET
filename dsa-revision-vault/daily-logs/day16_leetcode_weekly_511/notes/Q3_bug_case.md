# Q3 Bug Case

Case:
s = "01"
strs = ["?0"]

total zeros in s = 1
fixed zero in "?0" = 1
So '?' must become 1.

Final target is "10".

Can "01" become "10" by sorting subsequences?
No, because sorting binary subsequences moves 0 left, not right.

Correct prefix maximum:
curZero + min(curQuestion, needQuestionAsZero)

Here needQuestionAsZero = 0,
so at prefix 0 max zero = 0,
but source prefix has 1 zero.
False.
