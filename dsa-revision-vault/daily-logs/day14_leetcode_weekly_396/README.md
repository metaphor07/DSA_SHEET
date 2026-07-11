# Day 14 - LeetCode Weekly Contest 396

Contest Link: https://leetcode.com/contest/weekly-contest-396/

## Contest Status

| Problem | Status | Color | Notes |
|---|---|---|---|
| Q1. Valid Word | Submitted | 🟢 Green | Character classification |
| Q2. Minimum Operations to Make Word K-Periodic | Submitted | 🟢 Green | Count most frequent k-block |
| Q3. Minimum Length of Anagram Concatenation | Submitted | 🟢 Green | Try divisors and compare frequency |
| Q4. Minimum Cost to Equalize Array | Upsolved | 🔴 Red | Deficit pairing + target candidates |

## Main Learnings

Q1: Check length, invalid characters, at least one vowel, and at least one consonant.

Q2: The final string must consist of repeated same block of length k. Keep the most frequent block and change all others.

Q3: The answer length must divide n. For each divisor length, compare frequency of every block with the first block.

Q4: For a fixed target, deficits determine cost. A pair operation can increment two different elements, so max pairs = min(total / 2, total - maxNeed).
