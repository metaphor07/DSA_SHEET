# Q3 Intuition - Minimum Number of Operations to Satisfy Conditions

Conditions:
1. All cells in the same column must be equal.
2. Adjacent columns must have different values.

First calculate:

cost[col][digit]

Meaning:
operations needed to make the whole column equal to digit.

For a column:
cost = number of rows - frequency of chosen digit in that column.

Then choose one digit for each column while adjacent columns cannot have the same digit.

This is Paint House style DP.
