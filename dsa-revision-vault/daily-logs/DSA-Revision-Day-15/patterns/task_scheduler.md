# Pattern: Task Scheduler

Formula:
```text
answer = max(total tasks, (maxFreq - 1) * (n + 1) + countMaxFreq)
```

Where:
```text
maxFreq = highest frequency of any task
countMaxFreq = number of tasks having maxFreq
```

Memory hook:
```text
Most frequent task creates the frame.
Other tasks fill gaps.
```
