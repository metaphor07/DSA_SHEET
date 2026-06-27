# Day 5 Mistake Analysis

## What went well

First 3 questions were submitted successfully. This is a clear improvement from earlier contests.

## Q4 Missed Pattern

The missing trigger was:

maximum Manhattan distance among points

This should immediately suggest:

x + y
x - y

For Manhattan distance problems, always check whether this transform can simplify the problem.

## Data Structure Gap

The second missing part was multiset.

Use multiset when:
- values must remain sorted
- duplicates are possible
- you need quick min and max after insert/delete

For this problem:
- remove one point
- check current min/max
- insert it back

So multiset is a natural fit.
