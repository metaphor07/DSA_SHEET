# Q1 Intuition - Transform Array to All Equal Elements

Final array can be either:
- all 1
- all -1

For a fixed target, scan from left to right.

At index i, if nums[i] is not target, the only way to fix it is to use operation at i:
flip nums[i] and nums[i+1].

After moving past i, we can never change it again safely.

So check both targets and see whether operations <= k.
