# Pattern: Top K using Heap

## Kth largest using min heap
```cpp
priority_queue<int, vector<int>, greater<int>> pq;

for (int x : nums) {
    pq.push(x);
    if (pq.size() > k) pq.pop();
}

return pq.top();
```

## Memory hook
Min heap of size K keeps K largest elements.
Top is kth largest.
