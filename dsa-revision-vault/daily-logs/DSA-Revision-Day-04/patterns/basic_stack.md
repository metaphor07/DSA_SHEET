# Pattern: Basic Stack

## Use when
You need to process things in reverse order or match pairs.

## Common triggers
- valid parentheses
- expression evaluation
- undo/backtracking simulation
- remove adjacent duplicates

## Template
```cpp
stack<char> st;

for (char c : s) {
    if (is_opening(c)) {
        st.push(c);
    } else {
        if (st.empty()) return false;
        if (!matches(st.top(), c)) return false;
        st.pop();
    }
}

return st.empty();
```
