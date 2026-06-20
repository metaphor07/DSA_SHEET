# Valuable Suggestions After Day 1

## Contest Habit

After solving Q1 and Q2 quickly, do not rush into coding Q3.

Spend 5 minutes asking:

1. What is the operation really doing?
2. Is the decision local or global?
3. Do I need stack, heap, set, map, or greedy?
4. Does deleting directly cause index shifting issues?
5. Can I mark deleted positions instead?

## Pattern From Q3

Whenever the problem says:

- lexicographically minimum
- remove one character
- choose among many possible characters

Think:
- smallest character
- rightmost/leftmost occurrence
- priority queue
- ordered set
- 26 buckets for lowercase letters

## Pattern From Q4

Whenever the problem asks:

- subarray AND
- subarray OR
- closest to k
- distinct bitwise result

Think:
Maintain all distinct bitwise values ending at current index.

Template:

vector<int> prev;

for each x:
    curr = {x}
    for val in prev:
        curr.push_back(val & x)
    remove duplicates
    update answer
    prev = curr

## Next Contest Target

Your Day 2 target:

Q1: under 10 minutes
Q2: under 25 minutes
Q3: correct idea within 30 minutes

Even if Q3 code fails, idea recognition is progress.
