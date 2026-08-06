# Q2 Memoization Note

Memoization can calculate ways using the currently discovered coins:

countWays(idx, amount)

Choices:
- not take current coin
- take current coin again, because coin supply is unlimited

But this version is slower because the memo table is rebuilt after every discovered coin.

Use tabulation for submission.
Memoization is only useful for understanding the recurrence.
