# Pattern: Monotonic Increasing Stack

## Use when
You need next smaller / previous smaller.

## Common problems
- LC 84 - Largest Rectangle in Histogram
- Sum of subarray minimums
- remove bigger elements

## LC 84 intuition
For every bar:
```text
area = height * width
```

Width is determined by:
```text
next smaller on right - previous smaller on left - 1
```

## Template
```cpp
stack<int> st;

for (int i = 0; i <= n; i++) {
    int curr = (i == n) ? 0 : heights[i];

    while (!st.empty() && curr < heights[st.top()]) {
        int h = heights[st.top()];
        st.pop();

        int right = i;
        int left = st.empty() ? -1 : st.top();

        int width = right - left - 1;
        ans = max(ans, h * width);
    }

    st.push(i);
}
```
