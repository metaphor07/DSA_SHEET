# Pattern: Word Search II

## Steps
```text
1. Build Trie of all words.
2. DFS from every board cell.
3. Move only if Trie child exists.
4. Mark visited using '#'.
5. When word is found, add answer and clear word.
6. Prune useless Trie branches.
```

## Memory hook
Trie reduces search space.  
Pruning prevents repeated dead DFS.
