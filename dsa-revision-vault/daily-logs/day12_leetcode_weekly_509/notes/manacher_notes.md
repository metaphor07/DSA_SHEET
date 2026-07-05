# Manacher Notes for Arrays

Manacher is usually taught for strings, but it works for arrays too.

Instead of comparing characters:

s[i - k] == s[i + k]

we compare numbers:

nums[i - k] == nums[i + k]

d1[i]:
radius of odd palindrome centered at i

d2[i]:
radius of even palindrome centered between i-1 and i

For odd:
left = i - d1[i] + 1
right = i + d1[i] - 1

For even:
left = i - d2[i]
right = i + d2[i] - 1
