# Pattern: Task Scheduler

Formula:
```text
max(totalTasks, (maxFreq - 1) * (n + 1) + countMax)
```

Memory hook:
```text
Most frequent task creates the skeleton.
Other tasks fill idle gaps.
```
