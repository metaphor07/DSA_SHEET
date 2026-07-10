# Q2 Mistake - Why Sum Alone Is Not Enough

Your direction of removing two elements was correct.

Bug:
temp -= nums1[i] - nums1[j];

It should remove both values:
temp -= nums1[i] + nums1[j];

But even after fixing this, sum checking is not enough.

Correct process:
1. Sort nums1 and nums2.
2. Try removing every pair from nums1.
3. Compute x from the first remaining element.
4. Verify every remaining nums1 element + x equals nums2.
5. Take minimum valid x.
