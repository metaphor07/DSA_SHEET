# Q4 Intuition - Minimize Manhattan Distances

Manhattan distance:

|x1 - x2| + |y1 - y2|

Important transformation:

For every point `(x, y)`, calculate:

sum = x + y
diff = x - y

Then maximum Manhattan distance among a set of points is:

max(
    max(sum) - min(sum),
    max(diff) - min(diff)
)

So after removing one point, we only need the min and max of:
- x + y
- x - y

A multiset is useful because:
- It keeps values sorted.
- It allows duplicates.
- `begin()` gives minimum.
- `rbegin()` gives maximum.
- `erase(find(value))` removes only one occurrence.
