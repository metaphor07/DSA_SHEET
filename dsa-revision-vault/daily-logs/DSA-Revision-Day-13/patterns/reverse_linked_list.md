# Pattern: Reverse Linked List

```cpp
ListNode* prev = nullptr;
ListNode* curr = head;

while (curr != nullptr) {
    ListNode* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
}

return prev;
```

## Memory hook
Save next. Reverse current. Move prev and curr.
