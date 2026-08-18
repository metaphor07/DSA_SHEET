# Visa — Online Assessment Prep
*Coding / DSA Section — Reconstructed from your OA screenshots*

> **Note:** Problem statement, function description, and constraints below are transcribed directly from your 3 screenshots (some fragments repeat across images — combined into one clean statement). This is a genuinely hard problem (geometry + search) — I traced it back to its original source (a TopCoder SRM problem) to confirm the intended algorithm rather than guessing. Solution approach, extra test cases, and reference code are my own additions, verified against your OA's own sample output.

---

## Question 1: Minimum Enclosing Square (minArea)

### Problem Statement
*(From screenshot)*

Given a list of points described by their `(x, y)` coordinates on a two-dimensional plane, construct a square surrounding at least `k` of the given `n` points. That area should be minimal, and the square must meet the following conditions:
- The x-coordinates and y-coordinates of the square's corners should be integers.
- The sides of the square should be parallel to the coordinate axes.
- At least `k` of the given `n` points should lie **strictly inside** the square drawn. Strictly inside means they cannot lie on a side of the square.

**Example (from screenshot):** Given `n=3` points `(1,1)`, `(1,2)`, `(2,1)` and `k=3` (surround all three points), the minimum area square is `9` units — going from origin `(0,0)` to `(3,3)`.

### Function Description
Complete the function `minArea`. It returns the minimum possible area of the square that satisfies the constraints, as an integer.

`minArea` has the following parameters:
- `x[x[0],...,x[n-1]]` — an array of integer x-coordinates
- `y[y[0],...,y[n-1]]` — an array of integer y-coordinates
- `k` — an integer, the minimum number of points to strictly enclose

### Constraints
*(From screenshot)*
- `2 ≤ n ≤ 100`
- `-10^9 ≤ x, y ≤ 10^9`
- `1 ≤ k ≤ n`

### Sample Case (from screenshot)
```
x = [1, 1, 2]
y = [1, 2, 1]
k = 3
```
**Output: `9`**

### Approach (Mentor Notes)

This is a genuinely hard one — it's a real geometry/search problem, not a standard pattern. I traced it back to its actual source: **TopCoder SRM 614, Division 1, 250-point problem "MinimumSquare"** — your OA is using the exact same problem (same constraints: `n ≤ 100`, coordinates up to `±10^9`; same class/method name `minArea`).

**Key trick — handle "strictly inside" by solving an easier version first:**
- It's much easier to first solve: *find the minimal square where points are allowed to touch the boundary* (inclusive), then fix up the "strictly inside" requirement afterward.
- **Why this works:** since all coordinates are integers, if you take an inclusive-boundary square of side `w` and expand it outward by exactly 1 unit on every side (making the new side `w + 2`), every point that was touching the old boundary is now strictly inside the new one, and nothing that was inside moves outside. So: solve the inclusive version to get minimal width `w`, then the real answer is `(w + 2)²`.
- Check against the sample: inclusive square around `(1,1)`,`(1,2)`,`(2,1)` has minimal side `1` (from `(1,1)` to `(2,2)`, touching all three). Expand: `1 + 2 = 3`. Area = `3² = 9`. ✔️ Matches exactly.

**Finding the minimal inclusive square:**
- Key geometric insight: the optimal square's left edge always passes through some point's x-coordinate, and its bottom edge always passes through some point's y-coordinate (there's no benefit to placing an edge where no point constrains it — you could always shrink the square further).
- So: try every point's x-coordinate as the candidate **left edge** `l`, and every point's y-coordinate as the candidate **bottom edge** `b` (`O(n²)` combinations, since `n ≤ 100`).
- For each `(l, b)` pair, only consider points with `x ≥ l` and `y ≥ b` (points to the top-right of this corner). For each such point, the smallest square with this corner that would include it needs width `max(x - l, y - b)`.
- Sort these required widths ascending — the **k-th smallest** value is exactly the minimal width needed for at least `k` points to fit in a square anchored at `(l, b)`.
- Take the minimum of this value across all `(l, b)` pairs — that's your minimal inclusive width. Then apply the `+2` fix-up.
- **Complexity:** `O(n² · n log n) = O(n³ log n)` — with `n ≤ 100`, this is roughly 10⁶–10⁷ operations, comfortably within limits.

### Reference Solution (C++)
```cpp
long long minArea(vector<int>& x, vector<int>& y, int k) {
    int n = x.size();
    vector<int> xs(x), ys(y);
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    long long bestW = LLONG_MAX;

    for (int l : xs) {
        for (int b : ys) {
            vector<long long> widths;
            for (int i = 0; i < n; i++) {
                if (x[i] >= l && y[i] >= b) {
                    widths.push_back(max((long long)(x[i] - l), (long long)(y[i] - b)));
                }
            }
            if ((int)widths.size() >= k) {
                sort(widths.begin(), widths.end());
                bestW = min(bestW, widths[k - 1]);
            }
        }
    }
    long long side = bestW + 2;
    return side * side;
}
```
*Verified: `minArea([1,1,2], [1,2,1], 3)` → `9`, matching your OA's sample exactly.*

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `x=[1,1,2], y=[1,2,1], k=3` | `9` | From screenshot |
| `x=[0,10], y=[0,10], k=2` | `144` | Added — two far-apart points, both must fit; tests large-span handling |
| `x=[0,0,0,10], y=[0,1,2,10], k=3` | `16` | Added — 3 clustered points + 1 distant outlier; tests that the algorithm correctly ignores the outlier when k doesn't require it |
| `x=[5], y=[5], k=1` | `4` | Added — edge case: a single point still needs a side-2 square to be *strictly* inside |

*All outputs above were computed and verified using the reconstructed algorithm — not guesses.*

### Equivalent Question (for cross-reference)
This is a **direct adaptation of TopCoder SRM 614, Division 1, "MinimumSquare"** (250-point problem). It's not on LeetCode or GfG under this exact name, but the TopCoder original — same constraints, same method signature — is the closest authoritative reference if you want to dig into editorial writeups:
`web.eecs.utk.edu/~jplank/topcoder-writeups/2014/MinimumSquare/MinimumSquare.pdf` (a university course write-up walking through the exact same brute-force-to-optimized derivation used above).

If you want LeetCode-style practice on the *related* but simpler idea (rectangles from a point set, no "at least k" requirement), **LeetCode 939: Minimum Area Rectangle** is a good adjacent workout — different problem, but same "reason about axis-aligned shapes from a point set" muscle.

---

## What Else Was in This Folder

Only 3 files total in the Visa folder, all part of this single question (spread across 3 screenshots of the same scrolling screen). No additional questions found.
