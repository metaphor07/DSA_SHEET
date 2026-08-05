# Q2 Intuition - Count Special Triplets

For middle index j:

i < j < k
nums[i] == 2 * nums[j]
nums[k] == 2 * nums[j]

So contribution for j is:

leftFreq[2 * nums[j]] * rightFreq[2 * nums[j]]

Move nums[j] from right side to left side while scanning.
