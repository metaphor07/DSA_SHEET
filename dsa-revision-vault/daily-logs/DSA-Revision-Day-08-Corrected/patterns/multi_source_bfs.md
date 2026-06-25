# Pattern: Multi-source BFS

## Use when
Multiple starting points spread at the same time.

## Common problems
- LC 994 - Rotting Oranges
- 01 Matrix
- Walls and Gates
- Nearest distance problems

## Template
```cpp
queue<pair<int,int>> q;

// push all sources first

int minutes = 0;

while (!q.empty()) {
    int size = q.size();
    bool changed = false;

    for (int i = 0; i < size; i++) {
        auto [r, c] = q.front();
        q.pop();

        // visit valid neighbors
    }

    if (changed) minutes++;
}
```

## Memory hook
All sources start together. Each BFS level is one time unit.
