# Q4 Dry Run

Example:
edges = [[0,1,2],[2,0,4]]
query = [1,2]

Path:
1 -> 0 -> 2

Edge weights:
1 to 0 = 2
0 to 2 = 4

Total = 6
need = ceil(6/2) = 3

distance(1,0) = 2 < 3
distance(1,2) = 6 >= 3

Answer = 2.
