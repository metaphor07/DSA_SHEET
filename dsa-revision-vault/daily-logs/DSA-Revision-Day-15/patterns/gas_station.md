# Pattern: Gas Station

First check:
```text
if totalGas < totalCost:
    return -1
```

Greedy reset:
```text
tank += gas[i] - cost[i]

if tank < 0:
    start = i + 1
    tank = 0
```

Memory hook:
```text
If we fail at i, no station before i can be the answer.
```
