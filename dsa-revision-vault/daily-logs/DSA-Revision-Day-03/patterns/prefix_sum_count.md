# Pattern: Prefix Sum Count

## Use when
You need to count subarrays with exact condition:
- exact sum K
- exactly K odds
- divisible by K

## Template
```cpp
unordered_map<int, int> mp;
mp[0] = 1;

int prefix = 0;
int ans = 0;

for (int x : nums) {
    prefix += x;
    ans += mp[prefix - k];
    mp[prefix]++;
}
```

## Memory hook
Current prefix asks:
How many old prefixes were `prefix - target`?
