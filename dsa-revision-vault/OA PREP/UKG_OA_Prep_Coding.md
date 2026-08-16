# UKG — Online Assessment Prep
*Coding / DSA Section — Reconstructed from your OA screenshots*

> **Note:** Question text and sample cases marked *"From screenshot"* are taken directly from your images. Portions marked *"Reconstructed"* were completed by me where the screenshot was cropped, blurry, or cut off, using the visible fragments plus the standard problem this matches. Solution approach, extra test cases, and reference code are my own additions for practice.

---

## Question 1: Largest Magical String

### Problem Statement
*(Reconstructed — screenshots were split across 2 partial images with overlapping/cut text)*

A non-empty binary string is called **"good"** if the following two conditions are true:
1. The number of `0`'s is equal to the number of `1`'s.
2. For every prefix of the string, the number of `1`'s is not less than the number of `0`'s.

For example, `"110010"` is good, but `"11010"` is not (it doesn't have an equal count of `0`'s and `1`'s).

A good string can contain multiple good substrings. If two consecutive substrings are both good, they can be swapped, as long as the resulting string is still a good string. Two substrings are adjacent if the last character of the first occurs exactly one index before the first character of the second.

Given a good binary string `binString`, perform zero or more swap operations on its adjacent good substrings such that the resulting string represents the largest possible numeric value. Return that string.

### Function Description
Complete the function `largestMagical` in the editor below.

```cpp
string largestMagical(string binString)
```

**Parameters:**
- `string binString` — a good binary string

**Returns:**
- `string` — the largest possible string obtainable via adjacent good-substring swaps

### Sample Case (from screenshot)
```
binString = "1010111000"
```
There are (at least) two good substrings: `"1010"` and `"111000"`. Swapping them gives `"1110001010"`, which is the largest possible value obtainable.

**Output: `1110001010`**

### Approach (Mentor Notes)
This is a **recursive** decomposition + greedy-sort problem, not a search problem — don't overthink the swapping mechanic.

> ⚠️ **Correction note:** An earlier draft of this used a non-recursive decomposition — it only fixes the top level and silently leaves the interior of each piece unsorted. It happened to pass the OA's own sample case but fails on inputs where the whole string is a single top-level piece (e.g. `"11011000"`). The version below is the corrected, fully recursive approach — verified against LeetCode's official examples.

- **Key insight:** repeatedly swapping ADJACENT good substrings is equivalent to being able to freely permute the string's "primitive" good pieces into any order (same idea as bubble sort — enough adjacent swaps = any permutation) — and this applies at **every level of nesting**, not just the outermost one.
- **Step 1 — Decompose:** scan left to right, treating `'1'` as `+1` and `'0'` as `-1`. Every time the running balance hits `0`, you've closed one primitive top-level piece.
- **Step 2 — Recurse:** every such piece looks like `'1' + interior + '0'`. The interior is itself a good binary string (possibly empty) — recursively apply this whole algorithm to the interior **before** doing anything else. This is the step the buggy version skipped.
- **Step 3 — Rewrap:** after recursively solving the interior, rebuild the piece as `'1' + (recursively solved interior) + '0'`.
- **Step 4 — Sort:** sort all top-level (now internally-optimal) pieces in descending string order and concatenate.
- **Complexity:** O(n log n) dominated by sorting at each recursion level.

### Reference Solution (C++) — Corrected
```cpp
string largestMagical(string binString) {
    vector<string> pieces;
    int bal = 0, start = 0;
    for (int i = 0; i < (int)binString.size(); i++) {
        bal += (binString[i] == '1') ? 1 : -1;
        if (bal == 0) {
            // recurse on the interior BEFORE rewrapping — this is the fix
            string inner = largestMagical(binString.substr(start + 1, i - start - 1));
            pieces.push_back('1' + inner + '0');
            start = i + 1;
        }
    }
    sort(pieces.begin(), pieces.end(), greater<string>());
    string ans;
    for (auto &s : pieces) ans += s;
    return ans;
}
```
*Verified against LeetCode's own examples: `"11011000" -> "11100100"`, and `"10" -> "10"`. Also re-verified against your original OA sample: `"1010111000" -> "1110001010"`.*

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `binString = "1010111000"` | `"1110001010"` | From screenshot |
| `binString = "1100"` | `"1100"` | Added — single-piece edge case |
| `binString = "101100"` | `"110010"` | Added — two pieces, different lengths |
| `binString = "10101100"` | `"11001010"` | Added — three pieces, tests sort tie-break |
| `binString = "11011000"` | `"11100100"` | Added — LeetCode 761 official example; exposes the recursion bug if your solution skips it |
| `binString = "10"` | `"10"` | Added — LeetCode 761 official example; minimal case |

*All outputs above were computed and verified against the corrected recursive algorithm.*

### Equivalent Question (for cross-reference)
This matches **[LeetCode 761: Special Binary String](https://leetcode.com/problems/special-binary-string/)** almost exactly — **Difficulty: Hard**. Same rules, same swap mechanic, same goal (largest result). Their sample function name is `makeLargestSpecial` instead of `largestMagical`, and they ask for lexicographically largest rather than "largest numeric value" — for binary strings starting with `1`, these two are equivalent.

Solve it there directly for judged practice.

---

## Question 2: Find Maximum Greatness

### Problem Statement
*(Reconstructed — combined from 4 overlapping screenshots)*

Given an array `arr`, we can rearrange it to form another array `rearranged_arr`. The **greatness** of the array is defined as the number of indices `i` (`0 ≤ i < n`) where `rearranged_arr[i] > arr[i]`.

Given the initial array `arr`, find the maximum possible greatness achievable by some rearrangement of `arr`.

### Function Description
Complete the function `findMaximumGreatness` in the editor below.

```cpp
int findMaximumGreatness(vector<int> arr)
```

**Parameters:**
- `int arr[n]` — the original array

**Returns:**
- `int` — the maximum greatness achievable

### Sample Cases (from screenshot)
**Case 0:** `arr = [1, 3, 5, 2, 1, 3, 1]`
Optimal `rearranged_arr = [2, 5, 1, 3, 3, 1, 1]`. At indices 0, 1, 3, 4, `rearranged_arr[i] > arr[i]`.
**Output: `4`**

**Case 1:** `arr = [4, 1, 6, 3]`
Optimal `rearranged_arr = [6, 3, 1, 4]`. All indices except index 2 are "great".
**Output: `3`**

### Approach (Mentor Notes)
This is the self-matching version of the classic **"Advantage Shuffle"** greedy pattern — very common in OAs, worth remembering by name.

- Think of it as two copies of the same array: a "target" copy (what must be beaten) and a "pool" copy (values you get to assign).
- Sort both ascending. Use two pointers: walk the pool from smallest to largest. For each pool value, check if it beats the smallest unbeaten target.
- If yes → it's a good match, count it, and move to the next (now-smallest) unbeaten target.
- If no → this pool value can't beat the current smallest target (or anything smaller), so it's "wasted" — it will eventually be used against the largest target instead, contributing nothing.
- This greedy is optimal because using your smallest usable "winner" on the smallest "beatable" target preserves your larger values for larger targets later.
- **Complexity:** O(n log n) for sorting; O(n) for the two-pointer scan.

### Reference Solution (C++)
```cpp
int findMaximumGreatness(vector<int> arr) {
    vector<int> target = arr;
    vector<int> pool = arr;
    sort(target.begin(), target.end());
    sort(pool.begin(), pool.end());
    int lo = 0, count = 0;
    for (int p : pool) {
        if (p > target[lo]) {
            count++;
            lo++;
        }
    }
    return count;
}
```

### Test Cases to Practice With

| Input | Expected Output | Source |
|---|---|---|
| `arr = [1, 3, 5, 2, 1, 3, 1]` | `4` | From screenshot |
| `arr = [4, 1, 6, 3]` | `3` | From screenshot |
| `arr = [5, 5, 5, 5]` | `0` | Added — all-equal edge case |
| `arr = [2, 7, 11, 15]` | `3` | Added — strictly increasing array |
| `arr = [1, 1, 1, 1, 2]` | `1` | Added — mostly duplicates |

*All "Added" outputs above were computed and verified against the reconstructed algorithm — they are not guesses.*

### Equivalent Question (for cross-reference)
This is the self-matching version of **[LeetCode 870: Advantage Shuffle](https://leetcode.com/problems/advantage-shuffle/)** — **Difficulty: Medium**. LeetCode's version uses two separate arrays `A` and `B` and asks you to permute `A` to maximize indices where `A[i] > B[i]`; your OA version uses the same array as both the target and the pool, but the greedy two-pointer solution is identical.

Solve it there directly for judged practice.

---

## What Else Was in This Folder (Skipped for Now)

Per your priority (DSA/coding only), I skipped the MCQ / code-review style questions found in the same UKG folder, e.g.:
- Good-pair array arrangement MCQ (adjacent sums even)
- Overtime-rate JavaScript code review MCQ (refactor suggestions)
- A 92-page `ukg.pdf` (likely a fuller company/role document — I haven't gone through this yet)

Say the word and I'll build these out next, or move to another company.
