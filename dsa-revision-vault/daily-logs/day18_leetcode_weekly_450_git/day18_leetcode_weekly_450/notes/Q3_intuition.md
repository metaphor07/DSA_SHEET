# Q3 Intuition - Grid Teleportation Traversal

This is not DP.

Normal grid move costs 1.
Teleport to same letter costs 0.

So use 0-1 BFS:
- push_front for 0-cost teleport edges
- push_back for 1-cost normal moves

Optimization:
Each portal letter should be expanded only once.
Otherwise, same portal cells are processed repeatedly and can TLE.
