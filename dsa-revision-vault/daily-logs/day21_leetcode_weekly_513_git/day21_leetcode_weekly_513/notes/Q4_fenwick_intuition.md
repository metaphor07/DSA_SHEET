# Q4 Fenwick Tree Explanation

After transformation:
Need count subarrays with sum <= 0.

Using prefix sums:
subarray l...r sum = pref[r+1] - pref[l]

Need:
pref[r+1] - pref[l] <= 0
pref[l] >= pref[r+1]

So when processing current prefix pref[j], count previous prefixes that are >= pref[j].

Fenwick tree normally gives count of <= x.
So:
previousPrefixes = j
smallerPrefixes = count of previous prefixes < pref[j]
valid = previousPrefixes - smallerPrefixes

Use coordinate compression because prefix sums can be large or negative.
