# Pattern: Partition Labels

## State
```text
end = farthest last occurrence of all chars seen in current partition
```

## Rule
```text
if i == end:
    cut partition
```

## Memory hook
Keep extending partition until all seen chars end inside it.
