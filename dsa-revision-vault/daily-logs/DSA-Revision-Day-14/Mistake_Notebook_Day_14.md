# Mistake Notebook - Day 14

## Revision
All revision problems are Green:
- LC 143 - Reorder List
- LC 19 - Remove Nth Node From End
- LC 139 - Word Break

## Today's 5 Mixed Questions
All marked Red:
- LC 49 - Group Anagrams
- LC 11 - Container With Most Water
- LC 128 - Longest Consecutive Sequence
- LC 417 - Pacific Atlantic Water Flow
- LC 152 - Maximum Product Subarray

Reason:
```text
Pattern switching was weak.
Need to identify the pattern without topic hints.
```

## LC 417 Mistakes
```text
Boundary condition used || instead of &&.
Visited check was missing.
```

Correct hook:
```text
Start from oceans.
Move inward only to higher/equal height.
Use visited.
```

## LC 152 Hook
```text
Negative flips max/min.
Zero resets product.
Prefix-suffix scan is also valid.
```
