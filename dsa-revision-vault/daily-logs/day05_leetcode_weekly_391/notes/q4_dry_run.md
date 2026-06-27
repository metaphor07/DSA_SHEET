# Q4 Dry Run

Example:

points = [[3,10], [5,15], [10,2], [4,4]]

Index-wise:

0 -> (3,10)
1 -> (5,15)
2 -> (10,2)
3 -> (4,4)

| index | point | x+y | x-y |
|---|---|---:|---:|
| 0 | (3,10) | 13 | -7 |
| 1 | (5,15) | 20 | -10 |
| 2 | (10,2) | 12 | 8 |
| 3 | (4,4) | 8 | 0 |

Initial sets:

sumSet  = {8, 12, 13, 20}
diffSet = {-10, -7, 0, 8}

## Remove point 0

After removing 13 and -7:

sumSet  = {8, 12, 20}
diffSet = {-10, 0, 8}

maxSum - minSum = 20 - 8 = 12
maxDiff - minDiff = 8 - (-10) = 18

curr = 18
ans = 18

## Remove point 1

After removing 20 and -10:

sumSet  = {8, 12, 13}
diffSet = {-7, 0, 8}

maxSum - minSum = 13 - 8 = 5
maxDiff - minDiff = 8 - (-7) = 15

curr = 15
ans = 15

## Remove point 2

After removing 12 and 8:

sumSet  = {8, 13, 20}
diffSet = {-10, -7, 0}

maxSum - minSum = 20 - 8 = 12
maxDiff - minDiff = 0 - (-10) = 10

curr = 12
ans = 12

## Remove point 3

After removing 8 and 0:

sumSet  = {12, 13, 20}
diffSet = {-10, -7, 8}

maxSum - minSum = 20 - 12 = 8
maxDiff - minDiff = 8 - (-10) = 18

curr = 18
ans = 12

Final answer = 12
