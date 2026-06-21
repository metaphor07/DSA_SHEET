# Pattern: Monotonic Decreasing Stack

## Use when
You need next greater element on the right.

## Common triggers
- next warmer day
- next greater element
- stock span style problems

## Template
```cpp
stack<int> st; // indexes

for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[i] > nums[st.top()]) {
        int idx = st.top();
        st.pop();
        ans[idx] = i - idx;
    }

    st.push(i);
}
```

## Memory hook
Stack stores unresolved indexes.
Current greater value resolves previous smaller values.
