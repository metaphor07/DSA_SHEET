# Q4 Dry Run

edges:
0-1 weight 2
1-2 weight 3
1-3 weight 5
1-4 weight 4
2-5 weight 6

query:
src1 = 2, src2 = 3, dest = 4

Pairwise distances:
dist(2,3) = 3 + 5 = 8
dist(2,4) = 3 + 4 = 7
dist(3,4) = 5 + 4 = 9

answer:
(8 + 7 + 9) / 2 = 12

Required subtree edges:
2-1, 1-3, 1-4

weights:
3 + 5 + 4 = 12
