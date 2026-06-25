# Revision TODO

## Revise Tomorrow

### LeetCode 1590 - Make Sum Divisible by P

Must revise this problem without seeing solution.

Key steps:

```cpp
long long total = 0;
for (int x : nums) total += x;

int target = total % p;
if (target == 0) return 0;
```

Then:

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

Return:

```cpp
return ans == n ? -1 : ans;
```

## Also Revise

1. Codeforces 1931D - Divisible Pairs
2. Codeforces 2093C - Simple Repetition
