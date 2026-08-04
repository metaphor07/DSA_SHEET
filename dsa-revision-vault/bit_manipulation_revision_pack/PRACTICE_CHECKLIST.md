# Bit Manipulation Practice Checklist

Use this file to track revision.

Legend:

```text
[ ] Not attempted
[Y] Needs revision
[G] Confident
```

---

## Fundamentals

- [ ] Check, set, clear, and toggle the i-th bit
- [ ] Count set bits using Brian Kernighan’s method
- [ ] Use `__builtin_popcount` and `__builtin_popcountll`
- [ ] Find the lowest set bit
- [ ] Remove the lowest set bit
- [ ] Check power of two
- [ ] Understand signed versus unsigned shifts
- [ ] Use `1LL` or `1ULL` safely

## XOR Patterns

- [ ] One unique value, all others twice
- [ ] Two unique values, all others twice
- [ ] One unique value, all others three times
- [ ] Missing number using XOR
- [ ] XOR from `1` to `n`
- [ ] XOR of range `[L, R]`
- [ ] Prefix XOR
- [ ] Count subarrays with XOR `k`

## Bitmask Enumeration

- [ ] Generate all subsets
- [ ] Iterate only through set bits
- [ ] Iterate all submasks
- [ ] Check whether one mask is a subset of another
- [ ] Perform set union, intersection, and difference with masks

## Bitmask DP

- [ ] Assignment DP using `dp[mask]`
- [ ] Pairing DP
- [ ] TSP-style `dp[mask][last]`
- [ ] Partition a mask using submasks
- [ ] Use `popcount(mask)` to determine the next index

## Advanced Patterns

- [ ] Maximum XOR pair using binary trie
- [ ] Range bitwise AND
- [ ] Add without `+`
- [ ] Reverse bits
- [ ] Hamming distance
- [ ] Gray code
- [ ] Next power of two

---

# Suggested 3-Day Revision

## Day 1

1. Basic operators
2. Check/set/clear/toggle
3. Lowest set bit
4. Count set bits
5. Power of two
6. Single Number
7. Missing Number
8. Hamming Distance

## Day 2

1. Single Number II
2. Single Number III
3. Prefix XOR
4. XOR Queries
5. Count subarrays with XOR `k`
6. Generate subsets
7. Iterate submasks

## Day 3

1. Assignment bitmask DP
2. Pairing bitmask DP
3. TSP-style DP
4. Maximum XOR using trie
5. Range bitwise AND
6. Full README revision
7. Solve two timed problems without notes
