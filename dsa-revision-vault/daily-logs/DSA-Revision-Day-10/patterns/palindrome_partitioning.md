# Pattern: Palindrome Partitioning

## Memory hook
```text
Cut the string at every valid palindrome.
```

## Template idea
```cpp
for (int end = start; end < s.size(); end++) {
    if (isPalindrome(s, start, end)) {
        path.push_back(s.substr(start, end - start + 1));
        dfs(end + 1);
        path.pop_back();
    }
}
```
