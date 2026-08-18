# Cimpress — Online Assessment Prep
*Coding / DSA Section — Reconstructed from your OA screenshots*

> **Note:** Question text below is combined from 3 screenshots (one had no readable text via OCR — I decoded and read the image directly). Constraints are reconstructed from a partially blurry/rotated photo of the screen; the exponent digits were hard to read cleanly, so I've flagged my best-guess reading below. Solution approach, extra test cases, and reference code are my own additions for practice, verified against your OA's sample case.

---

## Question 1: Maximum Balls

### Problem Statement
*(From screenshot — question title, body, and function description are directly transcribed)*

Bob is a math teacher with a class of `N` students. The marks obtained by the students are represented by the array `marks`. Bob wants to gift every student an equal number of balls. To do this, he needs to choose a number that is a **factor of the marks of all N students**.

In order to distribute the maximum number of balls, Bob can change the marks of **at most one student** to any positive number of his choice. Find the maximum number of balls Bob can give to every student after changing the marks of at most one student.

### Function Description
Complete the function `max_balls`. It takes 2 parameters and returns an integer:
- `N` — the number of students in the class
- `marks` — the marks of `N` students

```
int max_balls(int N, int[] marks)
```

### Constraints
*(Reconstructed — photo was angled/blurry on the exponents; reading as)*
- `2 ≤ N ≤ 10^5`
- `1 ≤ marks[i] ≤ 10^9`

### Sample Case (from screenshot)
```
N = 3
marks = [12, 3, 11]
```
Bob can change the marks of the 3rd student to `39`. The maximum possible number of balls each student can get is `3`.

**Output: `3`**

### Approach (Mentor Notes)
Strip away the story and this is a classic pattern: **"maximum GCD of an array after replacing one element."**

- The number of balls per student must be a common factor of everyone's marks — i.e. it must divide the GCD of the whole array.
- Since Bob can change one student's marks to **any** positive number he wants, that student's mark is never a constraint — he can always set it to a multiple of whatever GCD the *other* `N-1` students settle on. So changing one element to fix the answer is always possible.
- This means the problem reduces to: **find the maximum GCD achievable by removing exactly one element from the array.**
- Try removing each index one at a time and compute the GCD of the rest — checking this naively is `O(N)` per removal, `O(N²)` total, too slow for `N` up to `10^5`.
- **Efficient approach:** precompute a `prefixGCD[]` array (GCD of everything before index `i`) and a `suffixGCD[]` array (GCD of everything after index `i`) in one pass each. Then for every index `i`, the GCD of the array *without* index `i` is simply `gcd(prefixGCD[i-1], suffixGCD[i+1])`. Take the max over all `i`.
- **Complexity:** `O(N log(max(marks)))` — one pass to build prefix/suffix arrays, one pass to combine them; each GCD call is `O(log(max value))`.

### Reference Solution (C++)
```cpp
int max_balls(int N, vector<int>& marks) {
    vector<int> prefix(N + 1, 0), suffix(N + 1, 0);
    for (int i = 0; i < N; i++)
        prefix[i + 1] = __gcd(prefix[i], marks[i]);
    for (int i = N - 1; i >= 0; i--)
        suffix[i] = __gcd(suffix[i + 1], marks[i]);

    int best = 0;
    for (int i = 0; i < N; i++)
        best = max(best, __gcd(prefix[i], suffix[i + 1]));
    return best;
}
```
*Verified: `max_balls(3, [12, 3, 11])` → `3`, matching your OA's sample exactly.*

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `N=3, marks=[12, 3, 11]` | `3` | From screenshot |
| `N=4, marks=[8, 16, 24, 5]` | `8` | Added — removing the one "odd one out" (5) unlocks a much higher GCD |
| `N=2, marks=[7, 13]` | `13` | Added — edge case: with only 2 elements, you always keep the larger one and overwrite the other to match it |
| `N=5, marks=[6, 10, 15, 100, 7]` | `1` | Added — no single removal helps; every pair of remaining elements is still coprime somewhere |

*All outputs above were computed and verified using the prefix/suffix GCD solution — not guesses.*

### Equivalent Question (for cross-reference)
This is an exact match for a well-known GfG problem: **[Maximum possible GCD after replacing at most one element in the given array](https://www.geeksforgeeks.org/dsa/maximum-possible-gcd-after-replacing-at-most-one-element-in-the-given-array/)**. Same problem, same prefix/suffix GCD technique — solve it there directly for extra judged practice.

There isn't an identically-numbered LeetCode problem for this exact variant, but if you want a related LeetCode workout on GCD/array manipulation, **LeetCode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1** uses similar GCD-array intuition (Difficulty: Medium/Hard).

---

## What Else Was in This Folder

Only 3 files total in the Cimpress folder — all 3 were part of this single question (title screen, problem body, and constraints/explanation screen). No additional questions found in this folder.
