# Mistake Notebook - Day 16

## LC 211 - Design Add and Search Words
**Status:** Yellow  
**Pattern:** Trie + DFS wildcard

### Mistakes
```text
isEndOfWord was initialized as true.
addWord handled '.', but addWord never receives '.'.
search did not handle '.' using DFS.
```

### Correct memory hook
```text
addWord = normal Trie insert.
search:
normal char -> go one child.
'.' -> try all 26 children using DFS.
```

---

## LC 212 - Word Search II
**Status:** Yellow  
**Pattern:** Trie + Board DFS + Pruning

### Mistake / optimization issue
```text
Basic Trie + DFS gave TLE.
Need pruning after word is found and branch becomes useless.
```

### Correct memory hook
```text
Build Trie of words.
DFS board only through Trie children.
Mark board cell as '#'.
When word found, clear word to avoid duplicates.
When Trie branch becomes useless, prune it.
```

---

## LC 271 - Encode and Decode Strings
**Status:** Locked / Not Tried

### Note
Problem was locked on LeetCode, so not attempted.

### Standard memory hook
```text
Encode each string as: length + '#' + string.
Decode by reading length until '#', then take that many chars.
```
