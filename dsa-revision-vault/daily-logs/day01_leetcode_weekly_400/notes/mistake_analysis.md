# Day 1 Mistake Analysis

## What went well

You solved Q1 and Q2 within 30 minutes. This is a very good start.

Q1 tested direct simulation.
Q2 tested sorting and interval merge, which is a common OA pattern.

## Q3 Mistake

Your approach assumed that when a `*` appears, the removed character is related to the last character before the star.

That is not correct.

Correct rule:
For each `*`, remove the smallest available character from the current string.
If there are multiple same smallest characters, remove the rightmost one.

Why rightmost?
Because keeping smaller characters earlier gives a lexicographically smaller final string.

Example:

s = "aaba*"

Before star: "aaba"
Smallest character = 'a'
Positions of 'a' = 0, 1, 3

Remove index 3, not index 0 or 1.

Final = "aab"

## Q4 Learning

Bitwise AND has a useful property:

As a subarray grows, AND value can only stay same or decrease.

So for each index, we do not need all O(n) previous subarrays.
We only keep distinct AND values ending at the previous index.

For current x:

new AND values =
- x
- previous_value & x for all previous distinct AND values

The number of distinct AND values remains small, usually bounded by number of bits.

This pattern is important for:
- subarray bitwise AND
- subarray bitwise OR
- closest value to k
- count distinct bitwise values

## Suggestion

For the next 7 contests, your main target should be:

1. Solve Q1 and Q2 fast.
2. Spend calm time on Q3 pattern recognition.
3. After contest, upsolve Q3 fully.
4. For Q4, at least identify the topic.

Your Day 1 score is not bad. It shows speed is already decent.
Now we need to improve medium/hard pattern recognition.
