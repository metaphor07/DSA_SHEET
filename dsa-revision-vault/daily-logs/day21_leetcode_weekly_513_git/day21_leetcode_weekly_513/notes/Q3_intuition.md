# Q3 Intuition - Count of Unfinished Tasks After Each Shift

Tasks must be processed in order.

If a shift does not complete all tasks:
progress carries over.

If a shift completes all tasks:
answer is 0,
progress resets to 0,
unused time is discarded.

Use prefix sums:
tasks = [1,4,4]
prefix = [1,5,9]

doneTime tells how much work is completed in the current cycle.

To know how many tasks are completed:
completed = upper_bound(prefix, doneTime)

unfinished = n - completed

Before applying a shift:
remaining = totalTime - doneTime

If shift >= remaining:
all tasks complete, answer 0, reset doneTime = 0.
