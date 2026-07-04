# Pattern: Trie Core

Trie is a prefix tree.

## Insert
```text
For each char:
    if child does not exist, create it.
    move to child.
At end mark isEnd = true.
```
