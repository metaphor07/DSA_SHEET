# Bit Manipulation — One-Page Cheat Sheet

```cpp
// Check
(n & (1LL << i)) != 0

// Set
n |= (1LL << i);

// Clear
n &= ~(1LL << i);

// Toggle
n ^= (1LL << i);

// Remove lowest set bit
n &= (n - 1);

// Isolate lowest set bit
long long lowbit = n & -n;

// Count bits
__builtin_popcountll(n);

// Power of two
n > 0 && (n & (n - 1)) == 0;

// Lowest k bits set
(1LL << k) - 1;

// Generate all subsets
for (int mask = 0; mask < (1 << n); mask++)

// Iterate all non-empty submasks
for (int sub = mask; sub; sub = (sub - 1) & mask)

// Membership
mask & (1 << i)

// Add item
mask | (1 << i)

// Remove item
mask & ~(1 << i)

// XOR range
prefix[r + 1] ^ prefix[l]

// XOR 1...n pattern
n % 4 == 0 -> n
n % 4 == 1 -> 1
n % 4 == 2 -> n + 1
n % 4 == 3 -> 0

// Gray code
i ^ (i >> 1)
```

Recognition:

```text
duplicates cancel        -> XOR
small used/un-used state -> bitmask DP
all combinations         -> subset masks
all parts of one mask    -> submask iteration
maximum XOR              -> binary trie
range XOR                -> prefix XOR
range AND                -> common binary prefix
```

Safety:

```text
Use 1LL or 1ULL before large shifts.
Do not call clz/ctz with zero.
Use parentheses around bit expressions.
Avoid shifting by the integer width.
Prefer unsigned values for raw bit operations.
```
