# Pattern: Time Based Key-Value Store

For each key:
```text
vector<pair<int, string>> {timestamp, value}
```

get:
```text
binary search largest timestamp <= given timestamp
```
