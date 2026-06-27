# Pattern: Backtracking Core

## Template
```cpp
void backtrack(state) {
    if (base_case) {
        save_answer();
        return;
    }

    for (choice in choices) {
        make_choice();
        backtrack(next_state);
        undo_choice();
    }
}
```

## Memory hook
Choose -> Explore -> Undo.
