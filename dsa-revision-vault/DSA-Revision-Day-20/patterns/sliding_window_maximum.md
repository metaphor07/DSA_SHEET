# Pattern: Sliding Window Maximum

Use deque storing indices.

## Rules
```text
1. Remove indices outside window from front.
2. Remove smaller elements from back.
3. Push current index.
4. Front is answer when window size reaches k.
```
