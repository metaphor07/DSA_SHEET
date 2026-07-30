# Pattern: Time Based Key-Value Store

For each key:
```text
key -> vector<pair<int, string>>
```

## set
```text
push_back({timestamp, value})
```

## get
```text
binary search largest timestamp <= given timestamp
```
