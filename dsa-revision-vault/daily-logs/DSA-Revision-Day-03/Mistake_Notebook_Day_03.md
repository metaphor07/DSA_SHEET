# Mistake Notebook - Day 03

## LC 567 - Permutation in String
**Status:** Red  
**Pattern:** Fixed-size sliding window + frequency array

### Mistake
I returned true when the window length became greater than `s1.length()`.  
But permutation exists only when the frequency of current window equals frequency of `s1`.

### Memory hook
Fixed-size window of length `s1.size()`.  
Compare frequency of window with frequency of `s1`.

---

## LC 1248 - Count Number of Nice Subarrays
**Status:** Yellow  
**Pattern:** Prefix sum + HashMap

### Mistake
I did not identify the pattern quickly. I solved only after seeing the topic tag.

### Memory hook
Convert:
- odd number -> 1
- even number -> 0

Then count subarrays with sum `k`.

---

## LC 76 - Minimum Window Substring
**Status:** Red  
**Pattern:** Variable sliding window + need/window maps

### Mistake
I tried to build the substring directly using a temporary string.  
Correct approach is to maintain window `[l...r]`, track validity, and shrink while valid.

### Memory hook
Expand right until valid.  
Shrink left while valid.  
Save smallest valid window inside the shrinking loop.
