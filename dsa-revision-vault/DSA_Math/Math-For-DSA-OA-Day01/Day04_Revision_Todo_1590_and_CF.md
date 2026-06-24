# Day 4 Revision TODO

## Must Revise Tomorrow

### LeetCode 1590 - Make Sum Divisible by P

Key idea:
```text
total % p = target
```

Need to remove the smallest subarray whose sum remainder is `target`.

Prefix condition:
```text
(prefix[j] - prefix[i]) % p = target
```

So:
```cpp
need = (curr - target + p) % p;
```

Template:
```cpp
unordered_map<int, int> mp;
mp[0] = -1;

long long prefix = 0;
int ans = n;

for (int i = 0; i < n; i++) {
    prefix += nums[i];

    int curr = prefix % p;
    int need = (curr - target + p) % p;

    if (mp.find(need) != mp.end()) {
        ans = min(ans, i - mp[need]);
    }

    mp[curr] = i;
}
```

Important:
- `mp[0] = -1` handles subarray starting from index 0.
- Update `mp[curr] = i` after checking.
- Return `-1` if answer is the full array length.

## Pending Codeforces Problems

1. Codeforces 1931D - Divisible Pairs
2. Codeforces 2093C - Simple Repetition

Patterns:
```cpp
int rem = ((x % k) + k) % k;
int need = (k - rem) % k;
```

For difference divisible by k:
```text
same remainder
```
