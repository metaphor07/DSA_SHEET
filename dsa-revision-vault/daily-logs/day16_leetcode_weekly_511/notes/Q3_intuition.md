# Q3 Intuition - Transform Binary String

Sorting a binary subsequence puts all 0s before all 1s inside that subsequence.

This operation can move:
- 0s to the left
- 1s to the right

So for any prefix, number of zeros can only increase or stay the same.

For target with '?':
First check if total zeros can be achieved:
fixedZero <= totalZerosInS <= fixedZero + questionCount

Then decide how many '?' must become 0:
needQuestionAsZero = totalZerosInS - fixedZero

For every prefix:
maxZeroInPrefix = fixedZeroPrefix + min(questionPrefix, needQuestionAsZero)

This must be >= zerosSourcePrefix.
