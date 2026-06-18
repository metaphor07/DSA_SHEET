# LC 560 - Subarray Sum Equals K

## Status

- Current status: Red
- Last attempted: Day 001
- Time taken:
- Attempts: Approach was wrong
- Pattern: Prefix sum + HashMap count

## Why I failed

My approach was totally wrong because I did not use the key idea:

> If current prefix sum is `prefix`, then we need a previous prefix sum equal to `prefix - k`.

This problem is not sliding window because numbers can be negative.

## Pattern recognition trigger

When I see:

> Count number of subarrays with sum equal to K.

I should think:

> Prefix sum + HashMap storing frequency of old prefix sums.

## Brute force idea

Check every subarray sum using two loops.

Time: O(n^2)

Space: O(1)

## Optimal approach

Maintain a running prefix sum.

For every index:

```text
prefix = sum from index 0 to current index
```

If:

```text
prefix - oldPrefix = k
```

Then:

```text
oldPrefix = prefix - k
```

So we check how many times `prefix - k` appeared before.

Steps:

1. Create map `mp`.
2. Put `mp[0] = 1` because a subarray can start from index 0.
3. Traverse array.
4. Add current number to `prefix`.
5. Add `mp[prefix - k]` to answer.
6. Store current prefix in map.

## Easy example to memorize

Input:

```text
nums = [1, 2, 3], k = 3
```

Dry run:

```text
Start:
prefix = 0
mp = {0: 1}
ans = 0

num = 1
prefix = 1
need = prefix - k = -2
mp[-2] = 0
ans = 0
mp[1]++

num = 2
prefix = 3
need = prefix - k = 0
mp[0] = 1
ans = 1    // subarray [1, 2]
mp[3]++

num = 3
prefix = 6
need = prefix - k = 3
mp[3] = 1
ans = 2    // subarray [3]
mp[6]++
```

Output:

```text
2
```

## Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for (int x : nums) {
            prefix += x;

            int need = prefix - k;
            if (mp.find(need) != mp.end()) {
                ans += mp[need];
            }

            mp[prefix]++;
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n)
- Space: O(n)

## Edge cases

- Negative numbers
- Zero values
- `k = 0`
- Subarray starts from index 0
- Multiple previous prefix sums are same

## Final memory hook

> Count subarray sum K = current prefix asks: “how many old prefixes were prefix - k?”

