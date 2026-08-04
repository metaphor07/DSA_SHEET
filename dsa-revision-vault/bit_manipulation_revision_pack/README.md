# Bit Manipulation — DSA Revision Notes

> A compact C++17 revision guide for online assessments, interviews, contests, and bitmask-based problems.

---

## 1. Binary Basics

Every integer is stored as bits.

```text
13 = 1101₂
     ||||
     8421
```

For a zero-indexed bit position `i`:

```text
value of bit i = 2^i
mask for bit i = 1 << i
```

Use `1LL << i` when `i` may be `31` or larger.

---

## 2. Bitwise Operators

| Operator | Meaning | Example |
|---|---|---|
| `a & b` | AND | Bit is 1 only when both bits are 1 |
| `a \| b` | OR | Bit is 1 when at least one bit is 1 |
| `a ^ b` | XOR | Bit is 1 when bits are different |
| `~a` | NOT | Flips every bit |
| `a << k` | Left shift | Usually multiplies by `2^k` |
| `a >> k` | Right shift | Usually divides non-negative `a` by `2^k` |

Truth table:

```text
A B | A&B A|B A^B
0 0 |  0   0   0
0 1 |  0   1   1
1 0 |  0   1   1
1 1 |  1   1   0
```

Important XOR properties:

```text
x ^ x = 0
x ^ 0 = x
x ^ y = y ^ x
(x ^ y) ^ z = x ^ (y ^ z)
```

---

# 3. Must-Know Single-Bit Operations

Assume bit positions are zero-indexed.

## Check the i-th bit

```cpp
bool isSet = (n & (1LL << i)) != 0;
```

Pseudo code:

```text
mask = 1 shifted left by i
return whether n AND mask is non-zero
```

## Set the i-th bit

```cpp
n = n | (1LL << i);
```

## Clear the i-th bit

```cpp
n = n & ~(1LL << i);
```

## Toggle the i-th bit

```cpp
n = n ^ (1LL << i);
```

## Update the i-th bit to `0` or `1`

```cpp
n = (n & ~(1LL << i)) | (1LL * bit << i);
```

Simpler logic:

```text
if desired bit is 1:
    set bit i
else:
    clear bit i
```

---

# 4. Lowest Set Bit Tricks

## Remove the lowest set bit

```cpp
n = n & (n - 1);
```

Example:

```text
n       = 1011000
n - 1   = 1010111
n&(n-1) = 1010000
```

Uses:

- Count set bits
- Check power of two
- Iterate only over set bits
- Reduce a mask step-by-step

## Isolate the lowest set bit

```cpp
long long lowbit = n & -n;
```

Example:

```text
n        = 1011000
n & -n   = 0001000
```

Uses:

- Fenwick Tree
- Separate numbers using a differing bit
- Find position of the least significant set bit

## Clear all bits from bit `0` through bit `i`

```cpp
n = n & ~((1LL << (i + 1)) - 1);
```

## Keep only bits from bit `0` through bit `i`

```cpp
n = n & ((1LL << (i + 1)) - 1);
```

---

# 5. Counting Set Bits

## Brian Kernighan’s algorithm

```cpp
int countSetBits(long long n) {
    int count = 0;

    while (n != 0) {
        n &= (n - 1);
        count++;
    }

    return count;
}
```

Complexity:

```text
O(number of set bits)
```

## Built-in functions

```cpp
__builtin_popcount(x);      // int
__builtin_popcountll(x);    // long long
```

Other useful built-ins:

```cpp
__builtin_clz(x);       // leading zeros in unsigned int
__builtin_clzll(x);     // leading zeros in unsigned long long
__builtin_ctz(x);       // trailing zeros; x must be non-zero
__builtin_ctzll(x);
```

For non-zero `unsigned int x`:

```cpp
int highestSetBitIndex = 31 - __builtin_clz(x);
int lowestSetBitIndex  = __builtin_ctz(x);
```

For `unsigned long long x`:

```cpp
int highestSetBitIndex = 63 - __builtin_clzll(x);
```

Never call `clz` or `ctz` with zero.

---

# 6. Power-of-Two and Related Checks

## Check whether `n` is a power of two

```cpp
bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

Reason: a power of two contains exactly one set bit.

```text
8 = 1000
7 = 0111
8 & 7 = 0
```

## Check whether `n` is a power of four

```cpp
bool isPowerOfFour(int n) {
    return n > 0 &&
           (n & (n - 1)) == 0 &&
           (n & 0x55555555) != 0;
}
```

`0x55555555` has set bits at even positions:

```text
01010101010101010101010101010101
```

## Find the next power of two

For positive `n`:

```cpp
unsigned int nextPowerOfTwo(unsigned int n) {
    if (n <= 1) return 1;

    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}
```

For contest code, another option is:

```cpp
unsigned int answer = 1u << (32 - __builtin_clz(n - 1));
```

Handle `n <= 1` separately.

---

# 7. Odd, Even, Multiply, Divide

## Odd or even

```cpp
bool isOdd = (n & 1);
bool isEven = !(n & 1);
```

## Multiply by `2^k`

```cpp
n << k
```

## Divide non-negative `n` by `2^k`

```cpp
n >> k
```

Do not blindly replace ordinary multiplication or division with shifts. Modern compilers already optimize constant powers of two.

---

# 8. XOR Patterns You Must Recognize

## Pattern 1: Every number appears twice except one

```cpp
int singleNumber(const vector<int>& nums) {
    int answer = 0;

    for (int x : nums) {
        answer ^= x;
    }

    return answer;
}
```

Why:

```text
a ^ a = 0
0 ^ unique = unique
```

## Pattern 2: Missing number from `[0, n]`

```cpp
int missingNumber(const vector<int>& nums) {
    int answer = nums.size();

    for (int i = 0; i < (int)nums.size(); i++) {
        answer ^= i;
        answer ^= nums[i];
    }

    return answer;
}
```

Alternative:

```text
xor all expected values
xor all array values
equal values cancel
```

## Pattern 3: Two numbers appear once, all others twice

```cpp
pair<int, int> twoUniqueNumbers(const vector<int>& nums) {
    int totalXor = 0;

    for (int x : nums) {
        totalXor ^= x;
    }

    int differingBit = totalXor & -totalXor;

    int first = 0;
    int second = 0;

    for (int x : nums) {
        if (x & differingBit) {
            first ^= x;
        } else {
            second ^= x;
        }
    }

    return {first, second};
}
```

Reason:

```text
totalXor = unique1 ^ unique2
```

A set bit in `totalXor` means the two unique values differ at that bit.

## Pattern 4: Every number appears three times except one

Count every bit independently.

Pseudo code:

```text
answer = 0

for bit from 0 to 31:
    count how many numbers have this bit set

    if count modulo 3 is non-zero:
        set this bit in answer
```

C++:

```cpp
int singleNumberAppearingOnce(const vector<int>& nums) {
    uint32_t answer = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count = 0;

        for (int x : nums) {
            count += (static_cast<uint32_t>(x) >> bit) & 1u;
        }

        if (count % 3 != 0) {
            answer |= (1u << bit);
        }
    }

    return static_cast<int32_t>(answer);
}
```

Generalization:

```text
all numbers appear k times except one
count every bit modulo k
```

## Pattern 5: XOR from `1` to `n`

The result repeats every four values.

```cpp
long long xorOneToN(long long n) {
    switch (n & 3) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}
```

Pattern:

```text
n % 4 = 0 -> n
n % 4 = 1 -> 1
n % 4 = 2 -> n + 1
n % 4 = 3 -> 0
```

## XOR of a range `[L, R]`

```cpp
xor(L...R) = xor(1...R) ^ xor(1...(L-1))
```

```cpp
long long xorRange(long long left, long long right) {
    return xorOneToN(right) ^ xorOneToN(left - 1);
}
```

---

# 9. Swap Without Temporary Variable

```cpp
a ^= b;
b ^= a;
a ^= b;
```

Know the trick, but normally prefer:

```cpp
swap(a, b);
```

The XOR version is less readable and fails if both references point to the same memory location.

---

# 10. Bitmasking for Sets

When the total number of elements is small, an integer can represent a set.

For `n` elements numbered `0` to `n-1`:

```text
bit i = 1 means element i is selected
bit i = 0 means element i is absent
```

## Add an element

```cpp
mask |= (1LL << i);
```

## Remove an element

```cpp
mask &= ~(1LL << i);
```

## Check membership

```cpp
bool present = mask & (1LL << i);
```

## Toggle membership

```cpp
mask ^= (1LL << i);
```

## Set operations

```cpp
long long unionMask        = a | b;
long long intersectionMask = a & b;
long long symmetricDiff    = a ^ b;
long long differenceMask   = a & ~b;
```

## Check whether `a` is a subset of `b`

```cpp
bool isSubset = (a & b) == a;
```

Equivalent:

```cpp
bool isSubset = (a | b) == b;
```

---

# 11. Generate All Subsets

For an array of size `n`:

```cpp
for (long long mask = 0; mask < (1LL << n); mask++) {
    vector<int> subset;

    for (int i = 0; i < n; i++) {
        if (mask & (1LL << i)) {
            subset.push_back(nums[i]);
        }
    }

    // process subset
}
```

Complexity:

```text
There are 2^n subsets.
Checking n positions per subset gives O(n * 2^n).
```

Use when roughly:

```text
n <= 20 to 24
```

The exact limit depends on work per mask and time limit.

---

# 12. Iterate Over Set Bits Only

```cpp
long long current = mask;

while (current != 0) {
    long long lowbit = current & -current;
    int bit = __builtin_ctzll(current);

    // process bit or lowbit

    current &= (current - 1);
}
```

Complexity:

```text
O(number of set bits)
```

---

# 13. Iterate Over All Submasks of a Mask

```cpp
for (int sub = mask; sub != 0; sub = (sub - 1) & mask) {
    // process non-empty submask
}

// process submask 0 separately when needed
```

Including zero:

```cpp
int sub = mask;

while (true) {
    // process sub

    if (sub == 0) break;
    sub = (sub - 1) & mask;
}
```

Total complexity over all masks:

```text
sum of submasks of all masks = O(3^n)
```

Common uses:

- Partition a mask
- Subset DP
- Assign a subset to the current group/person
- Split selected elements into two parts

---

# 14. Bitmask Dynamic Programming

Use bitmask DP when:

- The number of objects is small, often `n <= 20`
- State depends on which items have already been used
- Order, assignment, pairing, or grouping is involved

Common states:

```cpp
dp[mask]
dp[mask][last]
dp[mask][position]
```

## Assignment DP template

Example: assign one unused job to each person.

```cpp
int solve(int mask) {
    int person = __builtin_popcount(mask);

    if (person == n) {
        return 0;
    }

    if (memo[mask] != -1) {
        return memo[mask];
    }

    int answer = INF;

    for (int job = 0; job < n; job++) {
        if ((mask & (1 << job)) == 0) {
            int candidate =
                cost[person][job] +
                solve(mask | (1 << job));

            answer = min(answer, candidate);
        }
    }

    return memo[mask] = answer;
}
```

State meaning:

```text
mask tells which jobs are already assigned
number of set bits tells which person comes next
```

Complexity:

```text
O(n * 2^n)
```

## Traveling Salesman style state

```cpp
dp[mask][last]
```

Meaning:

```text
minimum cost to visit exactly the nodes in mask
and finish at node last
```

Transition:

```text
try moving from last to an unvisited node next
```

Typical complexity:

```text
O(n^2 * 2^n)
```

---

# 15. Pairing With Bitmask DP

A frequent interview/contest pattern:

```text
n is small and even
pair unused elements
minimize or maximize total pairing score
```

Pseudo code:

```text
solve(mask):
    if all elements are used:
        return 0

    choose first unused i

    answer = best possible value

    for every unused j after i:
        mark i and j as used
        update answer using pairScore(i, j) + solve(newMask)

    return answer
```

Choosing the first unused element avoids generating the same pairing in different orders.

---

# 16. Common Mask Construction Tricks

## Lowest `k` bits set

```cpp
long long mask = (1LL << k) - 1;
```

Example:

```text
k = 5 -> 00011111
```

## Bits from `L` through `R` set

```cpp
long long mask =
    ((1LL << (R - L + 1)) - 1) << L;
```

Safer helper for 64-bit edge cases:

```cpp
unsigned long long rangeMask(int left, int right) {
    unsigned long long high =
        (right == 63) ? ~0ULL : ((1ULL << (right + 1)) - 1);

    unsigned long long low =
        (left == 0) ? 0ULL : ((1ULL << left) - 1);

    return high ^ low;
}
```

## Extract bits `L...R`

```cpp
long long value = (n >> L) & ((1LL << (R - L + 1)) - 1);
```

## Replace bits `L...R`

Pseudo code:

```text
1. Build mask with 1s from L to R
2. Clear that range in n
3. Shift replacement value by L
4. OR it into n
```

---

# 17. Prefix XOR

Prefix XOR works similarly to prefix sum.

```cpp
vector<int> prefix(n + 1, 0);

for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] ^ nums[i];
}
```

Range XOR:

```cpp
xor(left...right) = prefix[right + 1] ^ prefix[left]
```

Why:

```text
duplicate prefix bits cancel under XOR
```

Applications:

- Range XOR queries
- Count subarrays with XOR equal to `k`
- Trie-based maximum XOR problems

## Count subarrays with XOR equal to `k`

```cpp
long long countSubarraysWithXorK(const vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    frequency[0] = 1;

    int prefixXor = 0;
    long long answer = 0;

    for (int x : nums) {
        prefixXor ^= x;

        int needed = prefixXor ^ k;

        if (frequency.count(needed)) {
            answer += frequency[needed];
        }

        frequency[prefixXor]++;
    }

    return answer;
}
```

Reason:

```text
prefix[j] ^ prefix[i] = k

therefore:
prefix[i] = prefix[j] ^ k
```

---

# 18. Maximum XOR Using a Binary Trie

Pattern:

```text
Find two values whose XOR is maximum.
```

Greedy idea:

```text
For each bit from most significant to least significant:
    prefer the opposite bit because 1 at a higher position is more valuable
```

Pseudo code:

```text
insert every number into a binary trie

for each number:
    node = root
    currentXor = 0

    for bit from high to low:
        currentBit = bit of number

        if child with opposite bit exists:
            move there
            set this bit in currentXor
        else:
            move to same-bit child

    update answer
```

Typical complexity:

```text
O(n * B)
```

where `B` is usually `31` or `32`.

---

# 19. Range Bitwise AND

Problem pattern:

```text
Find left & (left+1) & ... & right
```

Only the common binary prefix remains.

## Method 1: Shift to common prefix

```cpp
int rangeBitwiseAnd(int left, int right) {
    int shifts = 0;

    while (left < right) {
        left >>= 1;
        right >>= 1;
        shifts++;
    }

    return left << shifts;
}
```

## Method 2: Remove lowest set bit from `right`

```cpp
int rangeBitwiseAnd(int left, int right) {
    while (left < right) {
        right &= (right - 1);
    }

    return right;
}
```

---

# 20. Add Two Integers Without `+`

```cpp
int add(int a, int b) {
    while (b != 0) {
        unsigned int carry =
            static_cast<unsigned int>(a & b) << 1;

        a = a ^ b;
        b = static_cast<int>(carry);
    }

    return a;
}
```

Reason:

```text
a ^ b      gives sum without carry
(a & b)<<1 gives carry
```

Repeat until no carry remains.

---

# 21. Reverse Bits

Pseudo code:

```text
answer = 0

repeat 32 times:
    shift answer left
    copy last bit of n into answer
    shift n right
```

C++:

```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t answer = 0;

    for (int i = 0; i < 32; i++) {
        answer = (answer << 1) | (n & 1u);
        n >>= 1;
    }

    return answer;
}
```

---

# 22. Hamming Distance

The Hamming distance between two numbers is the number of differing bit positions.

```cpp
int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
}
```

For all pairs, think bit-by-bit:

```text
At a bit position:
ones = count of numbers with bit 1
zeros = n - ones

number of differing unordered pairs = ones * zeros
```

---

# 23. Gray Code

Consecutive Gray code values differ in exactly one bit.

For index `i`:

```cpp
int gray = i ^ (i >> 1);
```

Generate `n`-bit Gray code:

```cpp
vector<int> grayCode(int n) {
    vector<int> answer;

    for (int i = 0; i < (1 << n); i++) {
        answer.push_back(i ^ (i >> 1));
    }

    return answer;
}
```

---

# 24. Parity

Parity tells whether the number of set bits is odd or even.

```cpp
int parity = __builtin_popcountll(n) & 1;
```

Or:

```cpp
bool oddParity = false;

while (n != 0) {
    oddParity = !oddParity;
    n &= (n - 1);
}
```

---

# 25. Check Whether Two Integers Have Opposite Signs

```cpp
bool oppositeSigns = (x ^ y) < 0;
```

This depends on signed integer representation and should be used carefully. A clearer version is usually:

```cpp
bool oppositeSigns = (x < 0) != (y < 0);
```

---

# 26. Common Problem Recognition Guide

| Problem statement signal | Likely technique |
|---|---|
| Every value appears twice except one | XOR all values |
| Two unique values, others appear twice | XOR partition using lowest set bit |
| Values appear `k` times except one | Count bits modulo `k` |
| Small `n`, choose subsets | Enumerate masks |
| Small `n`, used/un-used state | Bitmask DP |
| Assign jobs to people | `dp[mask]` |
| Visit every node exactly once | `dp[mask][last]` |
| Pair small number of elements | Pairing bitmask DP |
| Count differing bits | XOR + popcount |
| Maximum XOR pair | Binary trie |
| Range XOR query | Prefix XOR |
| Subarray XOR equals `k` | Prefix XOR + hash map |
| AND of an integer range | Common binary prefix |
| Power of two | `n > 0 && !(n & (n-1))` |
| Iterate subgroups of selected elements | Submask iteration |
| Need all combinations of flags/features | Bitmask representation |

---

# 27. Operator Precedence Traps

Always use parentheses when mixing bitwise operators with comparisons or arithmetic.

Bad or confusing:

```cpp
if (mask & 1 << i)
if (n & 1 == 0)
```

Recommended:

```cpp
if ((mask & (1LL << i)) != 0)
if ((n & 1) == 0)
```

Important precedence order, simplified:

```text
arithmetic
shifts
comparisons
&
^
|
&&
||
```

Do not rely on memory during a contest. Add parentheses.

---

# 28. Signed Integer and Overflow Traps

## Use `1LL`

Bad:

```cpp
1 << 40
```

Correct:

```cpp
1LL << 40
```

## Avoid shifting by the type width

Invalid or undefined:

```cpp
1ULL << 64
1 << 32
```

## Prefer unsigned values for raw bit manipulation

```cpp
uint32_t
uint64_t
unsigned int
unsigned long long
```

## Be careful with `~`

```cpp
~5
```

does not mean “flip only the visible bits of 5.” It flips every bit in the fixed-width integer representation.

To flip only the lowest `k` bits:

```cpp
long long result = (~n) & ((1LL << k) - 1);
```

## Right shifting a negative signed integer

The behavior is implementation-defined in older standards and may preserve the sign bit. Prefer unsigned values for predictable logical shifts.

---

# 29. Complexity Cheat Sheet

| Technique | Complexity |
|---|---|
| Check/set/clear/toggle one bit | `O(1)` |
| Count set bits using `n &= n-1` | `O(popcount(n))` |
| Scan all bits of an integer | `O(B)` |
| Generate all subsets | `O(n * 2^n)` |
| Iterate set bits | `O(popcount(mask))` |
| Iterate all submasks of one mask | `O(2^k)` where `k = popcount(mask)` |
| Iterate submasks for all masks | `O(3^n)` |
| Assignment bitmask DP | `O(n * 2^n)` |
| TSP-style bitmask DP | `O(n^2 * 2^n)` |
| Binary trie maximum XOR | `O(n * B)` |

`B` is the number of processed bits, usually `31`, `32`, or `64`.

---

# 30. Essential C++17 Helper Functions

```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using uint64 = unsigned long long;

bool isBitSet(uint64 n, int bit) {
    return (n & (1ULL << bit)) != 0;
}

uint64 setBit(uint64 n, int bit) {
    return n | (1ULL << bit);
}

uint64 clearBit(uint64 n, int bit) {
    return n & ~(1ULL << bit);
}

uint64 toggleBit(uint64 n, int bit) {
    return n ^ (1ULL << bit);
}

int countSetBits(uint64 n) {
    return __builtin_popcountll(n);
}

bool isPowerOfTwo(uint64 n) {
    return n != 0 && (n & (n - 1)) == 0;
}

uint64 lowestSetBit(uint64 n) {
    return n & (~n + 1);
}

uint64 removeLowestSetBit(uint64 n) {
    return n & (n - 1);
}
```

Note:

```cpp
n & (~n + 1)
```

is the unsigned equivalent of:

```cpp
n & -n
```

---

# 31. Fast Problem-Solving Checklist

Before coding, ask:

1. Is `n` small enough for `2^n`?
2. Does each bit represent selected/unselected or used/unused?
3. Are duplicate values supposed to cancel using XOR?
4. Is the answer related to differing bits?
5. Can prefix XOR transform a subarray query?
6. Is there one unique value among repeated values?
7. Is the problem asking for all submasks or a partition of a mask?
8. Do I need `1LL` or unsigned types?
9. Can I derive the next state using `mask | (1 << i)`?
10. Is `popcount(mask)` enough to determine the current index/person/step?

---

# 32. Debugging Checklist

When a bit solution fails, check:

```text
[ ] Are bit positions zero-indexed?
[ ] Did I use 1LL or 1ULL before shifting?
[ ] Can i reach 31, 32, 63, or 64?
[ ] Did I put parentheses around shifts and bitwise expressions?
[ ] Am I using signed values where unsigned is safer?
[ ] Did I handle n = 0?
[ ] Did I call clz/ctz with zero?
[ ] Did I process submask 0?
[ ] Did I use the correct number of bits?
[ ] Is the mask size 1 << n overflowing int?
[ ] Did I accidentally use logical && or || instead of bitwise & or |?
[ ] Is memoization initialized with a value that cannot be a valid answer?
[ ] Am I double-counting subset partitions?
```

---

# 33. Five-Minute Final Revision

Memorize these:

```cpp
// Check bit
(n & (1LL << i)) != 0

// Set bit
n | (1LL << i)

// Clear bit
n & ~(1LL << i)

// Toggle bit
n ^ (1LL << i)

// Remove lowest set bit
n & (n - 1)

// Isolate lowest set bit
n & -n

// Power of two
n > 0 && (n & (n - 1)) == 0

// Count set bits
__builtin_popcountll(n)

// Lowest k bits
(1LL << k) - 1

// Every subset
for (int mask = 0; mask < (1 << n); mask++)

// Every non-empty submask
for (int sub = mask; sub; sub = (sub - 1) & mask)

// Range XOR
prefix[r + 1] ^ prefix[l]

// XOR 1 to n
[n, 1, n + 1, 0][n % 4]

// Gray code
i ^ (i >> 1)
```

---

# 34. Recommended Practice Order

## Level 1 — Fundamentals

- Number of 1 Bits
- Power of Two
- Counting Bits
- Hamming Distance
- Reverse Bits
- Missing Number
- Single Number

## Level 2 — XOR Patterns

- Single Number II
- Single Number III
- Find the Original Array of Prefix XOR
- XOR Queries of a Subarray
- Count the Number of Beautiful Subarrays

## Level 3 — Bitmask Enumeration

- Subsets
- Letter Case Permutation
- Maximum Product of Word Lengths
- Partition to K Equal Sum Subsets
- Matchsticks to Square

## Level 4 — Bitmask DP

- Can I Win
- Partition to K Equal Sum Subsets
- Minimum XOR Sum of Two Arrays
- Number of Ways to Wear Different Hats
- Shortest Path Visiting All Nodes
- Traveling Salesman variants
- Assignment problem variants

## Level 5 — Trie and Advanced XOR

- Maximum XOR of Two Numbers in an Array
- Maximum XOR With an Element From Array
- Count Pairs With XOR in a Range
- Strong Pair XOR problems

---

# 35. One-Line Memory Map

```text
AND  -> keep common bits
OR   -> combine bits
XOR  -> find differences and cancel duplicates
NOT  -> flip bits
SHIFT -> move bit positions
MASK -> encode a subset or state
```

The most important idea is not memorizing tricks individually. Learn to recognize what each bit represents and how the state changes.
