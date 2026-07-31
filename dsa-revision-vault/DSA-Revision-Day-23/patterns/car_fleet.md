# Pattern: Car Fleet

Sort cars by position descending.

For each car:
```text
time = (target - position) / speed
```

If current car takes more time than the fleet ahead:
```text
new fleet
```

Otherwise:
```text
it catches the fleet ahead
```

## Memory hook
Process from closest to target.
Slower time ahead absorbs faster car behind.
