# Zepto — Online Assessment Prep
*Coding / DSA Section — Reconstructed from your OA screenshots*

> **Note:** This folder had 2 distinct coding questions. Question 1 is fully reconstructed and verified. Question 2 is missing its actual problem narrative in the screenshots (only the function description and I/O format were visible — the core "what is this problem asking" text was cut off), so I've flagged it rather than guess at what it's really asking.

---

## Question 1: Minimize Path Value

### Problem Statement
*(From screenshot, combined across 3 images)*

Given a graph `G` with `N` nodes and `M` edges (bidirectional). Every node is assigned a value `A[i]`. A **path** is a sequence of nodes starting at node `S` and ending at node `E`: `S → u1 → u2 → ... → E`.

**Value of a path** = the maximum absolute difference between the values of adjacent nodes anywhere along the path.

Given a start node `S` and end node `E`, find the minimum possible "value of path" over all paths from `S` to `E`.

### Function Description
Complete the function `pathValue`. It returns the minimum possible value of the path.

Parameters:
- `N` — number of nodes in graph `G`
- `M` — number of edges in graph `G`
- `S` — start node
- `E` — end node
- `edge` — the edges present in `G`
- `A` — the values of nodes in `G`

**Input format:**
1. First line: two space-separated integers `N M`
2. Second line: two space-separated integers `S E`
3. Next `M` lines: two space-separated integers `u v`, denoting an edge between `u` and `v`
4. Next line: `N` space-separated integers denoting node values

**Constraints:**
*(From screenshot)*
- `1 ≤ N ≤ 10^5`
- Use fast I/O

### Sample Case (from screenshot)
```
N = 5, M = 6, S = 1, E = 4
A = [3, 12, 4, 7, 13]   (nodes 1 through 5)
```
There are 4 simple paths from node 1 to node 4:
- `1→2→4`: value = max(|12−3|, |12−7|) = 9
- `1→3→4`: value = max(|4−3|, |7−4|) = 3
- `1→3→5→2→4`: value = 9 (bottlenecked by edge 3–5)
- `1→2→5→3→4`: value = 9 (bottlenecked by edge 3–5)

**Output: `3`** (the `1→3→4` path)

*(A second sample I/O block appeared in the screenshots, but the OCR text was too garbled — mismatched numbers with no clear way to separate node count, edges, and values — to reconstruct reliably. I've left it out rather than guess at numbers that might be wrong.)*

### Approach (Mentor Notes)
This is the classic **"minimax path" / "bottleneck shortest path"** pattern — don't treat it like a normal shortest-path problem where you sum edge weights; here you're minimizing the **worst single step** along the path.

- Think of each edge `(u, v)` as having a "cost" of `|A[u] − A[v]|`.
- You want the path from `S` to `E` where the **largest** edge cost along the path is as small as possible — not the path with the smallest total cost.
- **Modified Dijkstra works perfectly here:** instead of relaxing with `dist[v] = dist[u] + weight`, relax with `dist[v] = max(dist[u], weight(u,v))`, and only update if this is smaller than the current `dist[v]`. Everything else about Dijkstra (priority queue, greedy expansion) stays the same.
- This works because Dijkstra's greedy correctness argument only relies on the relaxation function being "monotonic" — `max` satisfies that just as well as `+` does.
- **Alternative approach (also valid):** sort all edges by `|A[u]-A[v]|` ascending, use Union-Find, and add edges one at a time until `S` and `E` become connected — the weight of the edge that connects them is the answer. (This is literally Kruskal's MST algorithm, stopped early — same idea as building a minimum bottleneck spanning tree.)
- **Complexity:** `O((N + M) log N)` with the Dijkstra approach; `O(M log M)` with the Kruskal/Union-Find approach.

### Reference Solution (C++) — Modified Dijkstra
```cpp
long long pathValue(int N, int M, int S, int E, vector<pair<int,int>>& edges, vector<int>& A) {
    vector<vector<int>> adj(N + 1);
    for (auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<long long> dist(N + 1, LLONG_MAX);
    dist[S] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (int v : adj[u]) {
            long long w = abs(A[u] - A[v]);
            long long nd = max(d, w);
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist[E];
}
```
*Verified: `pathValue` on the reconstructed example (`A=[3,12,4,7,13]`, edges `(1,2),(1,3),(2,4),(3,4),(3,5),(2,5)`, `S=1, E=4`) → `3`, matching the screenshot's worked explanation exactly.*

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `N=5,M=6,S=1,E=4, A=[3,12,4,7,13], edges=(1,2)(1,3)(2,4)(3,4)(3,5)(2,5)` | `3` | From screenshot's worked explanation |
| `N=4,M=4,S=1,E=4, A=[1,100,2,3], edges=(1,2)(1,3)(3,4)(2,4)` | `1` | Added — tests that the algorithm correctly avoids a huge-difference shortcut edge |
| `N=3,M=2,S=1,E=3, A=[5,5,5], edges=(1,2)(2,3)` | `0` | Added — all node values equal, minimum path value is always 0 |

*All outputs above were computed and verified using the modified-Dijkstra solution — not guesses.*

### Equivalent Question (for cross-reference)
Closest exact-concept match: **[LeetCode 1631: Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)** (Difficulty: Medium) — identical core idea (minimize the maximum absolute difference along a path), just applied to a 2D grid instead of an arbitrary graph. The modified-Dijkstra technique is exactly the same.

For the general-graph version (not grid), this is sometimes called the **"widest path problem"** or **"minimum bottleneck path"** — see **[GeeksforGeeks — Minimize the maximum difference between adjacent elements in a path (widest path problem articles)](https://www.geeksforgeeks.org/dsa/minimum-bottleneck-spanning-tree/)** for the Kruskal/Union-Find angle on the same idea.

---

## Question 2: `solve(k, m, r)` — ⚠️ Incomplete, needs a better screenshot

### What's visible
*(From screenshot — function description and I/O format only)*

- Function `solve` takes 3 parameters and returns an answer:
  - `k` — "represents the amount of coin your friend wants"
  - `m` — "represents the integer value"
  - `r` — "represents the number of coins"
- Input format: first line contains 3 space-separated integers `N, K, M` *(note: these variable names don't quite match the `k, m, r` described above — likely a naming inconsistency between the prose and the actual signature, common when OAs get lightly edited between versions)*
- Constraints: `1 ≤ N ≤ 10^3`, `1 ≤ K ≤ 10^2`, `1 ≤ M ≤ 10^3`
- Sample: input `4 2 2` → output `2`, explained as "There are 2 ways: (1,3), (2,4)"
- A second sample (`100 10 5`) has a garbled output value in the screenshot that I can't confidently read

### Why I'm not reconstructing this one
The screenshots I have only show the **function description and I/O format** — the actual problem narrative (what the story/scenario is, what's actually being counted or computed) isn't visible in any of the images. The "(1,3), (2,4)" hint suggests this might be a pair-counting problem (e.g., counting index pairs satisfying some condition related to `k` and `m`), but that's a guess dressed up as a guess — I don't have enough to reconstruct it responsibly the way I did for Question 1.

**If you can get a screenshot of the actual problem statement/title for this one** (scroll up from where these screenshots start), send it over and I'll finish this properly with the same verification standard as everything else.

---

## What Else Was in This Folder

Both questions covered above account for all 5 files in this folder (2 questions, spread across multiple screenshots each). No additional distinct questions found.
