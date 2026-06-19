# Mistake Notebook - Day 02

## Q209 - Minimum Size Subarray Sum

### What I did

I used sliding window correctly.

### What was wrong

The solution had repeated checks:

```cpp
if (sum >= target) len = min(len, r - l + 1);
```

This made the code less clean.

### Correct thinking

Whenever `sum >= target`, the current window is valid. Now shrink from the left while it remains valid and update the minimum length.

### Memory line

```txt
Minimum valid subarray => update answer while shrinking.
```

---

## Q974 - Subarray Sums Divisible by K

### What I did

I checked all subarrays using two loops.

### Why it failed

That is `O(n^2)` and gives TLE.

### Correct thinking

Use prefix sum remainder frequency.

If:

```txt
prefix1 % k == prefix2 % k
```

Then:

```txt
(prefix2 - prefix1) % k == 0
```

So every previous same remainder gives one valid subarray ending at current index.

### Important bug point

C++ can give negative remainder for negative numbers.

Use:

```cpp
if (rem < 0) rem += k;
```

### Memory line

```txt
Count subarrays divisible by k => count same prefix remainders.
```

---

## Q424 - Longest Repeating Character Replacement

### What I did wrong

I approached it like normal duplicate removal / direct replacement logic.

### Why that is wrong

We do not need to actually replace characters.

For any window:

```txt
characters_to_replace = window_size - count_of_most_frequent_character
```

The window is valid if:

```txt
window_size - maxFreq <= k
```

### Correct thinking

Keep expanding right and track the highest frequency of any character in the window.

If the window needs more than `k` replacements, shrink left.

### Memory line

```txt
Longest same-char window after k replacements => keep maxFreq.
Invalid if windowSize - maxFreq > k.
```

---

## Q3 - Longest Substring Without Repeating Characters

### What I did wrong

- Used `vector<int> track(26)` only for lowercase letters.
- Skipped spaces using `continue`, which can create infinite loop.
- Removed too much of the window when duplicate appeared.

### Correct thinking

Use ASCII frequency:

```cpp
vector<int> freq(256, 0);
```

When duplicate comes, shrink from left until duplicate is removed.

### Memory line

```txt
No repeating characters => while current char already exists, remove from left.
```

