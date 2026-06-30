# Pattern: Fast/Slow Pointer

## Use when
You need cycle detection or middle of linked list.

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```

## Memory hook
Fast moves 2 steps. Slow moves 1 step.
