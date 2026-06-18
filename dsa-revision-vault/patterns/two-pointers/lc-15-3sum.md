# LC 15 - 3Sum

## Status

- Current status: Yellow
- Last attempted: Day 001
- Time taken: 20 min
- Attempts: Solved, but not optimal
- Pattern: Sorting + two pointers + duplicate skipping

## Why I struggled

I was able to solve it, but my approach was not optimal. The key missing idea was:

> Sort the array, fix one number, then use two pointers to find the remaining pair.

## Pattern recognition trigger

When I see:

> Find unique triplets/pairs whose sum equals target.

I should think:

> Sort + fix one element + two pointers + skip duplicates.

## Brute force idea

Check every triplet using three loops.

Time: O(n^3)

Space: O(1), ignoring output

## Optimal approach

1. Sort the array.
2. Fix one index `i`.
3. Use two pointers:
   - `l = i + 1`
   - `r = n - 1`
4. Calculate:

```text
sum = nums[i] + nums[l] + nums[r]
```

5. If sum is 0, store the triplet.
6. Skip duplicate values for `l` and `r`.
7. If sum is smaller than 0, move `l++`.
8. If sum is greater than 0, move `r--`.

## Easy example to memorize

Input:

```text
nums = [-1, 0, 1, 2, -1, -4]
```

After sorting:

```text
[-4, -1, -1, 0, 1, 2]
```

Dry run:

```text
i = 1, nums[i] = -1
l = 2, nums[l] = -1
r = 5, nums[r] = 2

sum = -1 + -1 + 2 = 0
triplet = [-1, -1, 2]

Then skip duplicates and continue.
```

Output:

```text
[[-1, -1, 2], [-1, 0, 1]]
```

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return ans;
    }
};
```

## Complexity

- Time: O(n^2)
- Space: O(1), ignoring output

## Edge cases

- All positive numbers
- All negative numbers
- Multiple duplicate values
- Array size less than 3

## Final memory hook

> 3Sum = sort, fix one number, two-sum the rest, skip duplicates.

