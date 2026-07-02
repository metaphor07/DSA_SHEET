# Pattern: Meeting Rooms II

LC 253 was locked on LeetCode.

Core idea:
```text
Sort intervals by start time.
Use min heap of meeting end times.
```

Rule:
```text
If earliest ending meeting ends before current meeting starts:
    reuse that room
Else:
    need another room
```

Memory hook:
```text
Heap stores active meeting end times.
Heap size = rooms needed.
```
