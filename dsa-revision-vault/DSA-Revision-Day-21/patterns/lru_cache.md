# Pattern: LRU Cache

## Data structures
```text
unordered_map<int, Node*> mp
Doubly linked list
```

## Order
```text
head side = most recently used
tail side = least recently used
```

## Memory hook
Map gives node address.
DLL gives order and O(1) remove/move.
