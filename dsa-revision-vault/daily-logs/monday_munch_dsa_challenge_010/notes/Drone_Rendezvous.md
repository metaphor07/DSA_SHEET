# Drone Rendezvous

Brute force:
Use state (alpha_position, beta_position). This has O((N*M)^2) states and is unnecessary.

Intuition:
The drones move independently.
For each clear cell C:
Alpha reaches C in distA[C] rounds.
Beta reaches C in distB[C] rounds.
Since a drone can wait, meeting time at C is max(distA[C], distB[C]).

Optimal:
Run BFS from Alpha's start using K1.
Run BFS from Beta's start using K2.
Answer is minimum max distance over all clear cells reachable by both.

Movement:
A drone can move to any clear destination cell with Manhattan distance <= K.
Since K <= 10, scan the diamond around each cell.

Complexity:
O(N * M * K^2)
