# Pattern: Reorganize String

## Impossible check
```text
maxFreq > (n + 1) / 2
```

## Greedy
Use max heap.
Always pick two most frequent different characters.

## Memory hook
Most frequent character is the danger.
Top two heap picks keep same characters separated.
