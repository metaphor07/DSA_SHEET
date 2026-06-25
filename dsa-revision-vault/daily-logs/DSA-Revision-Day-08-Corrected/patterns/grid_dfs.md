# Pattern: Grid DFS

## Use when
You need to explore connected cells in a grid.

## Common problems
- LC 200 - Number of Islands
- LC 695 - Max Area of Island
- Flood Fill
- Surrounded Regions

## Template
```cpp
void dfs(vector<vector<char>>& grid, int r, int c) {
    int n = grid.size();
    int m = grid[0].size();

    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '0';

    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}
```

## Memory hook
When you visit land, sink it.
