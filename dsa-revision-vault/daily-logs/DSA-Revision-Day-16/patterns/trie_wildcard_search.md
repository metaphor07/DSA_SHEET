# Pattern: Trie Wildcard Search

## LC 211

For normal char:
```text
move to matching child
```

For dot:
```text
try all existing children using DFS
```

## Memory hook
'.' means branch into all possible children.
