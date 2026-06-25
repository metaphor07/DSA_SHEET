# Pattern: Clone Graph with HashMap

## Use when
You need to deep copy a graph.

## Key map
```text
old node -> cloned node
```

## DFS template
```cpp
unordered_map<Node*, Node*> mp;

Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    if (mp.count(node)) {
        return mp[node];
    }

    Node* clone = new Node(node->val);
    mp[node] = clone;

    for (Node* nei : node->neighbors) {
        clone->neighbors.push_back(cloneGraph(nei));
    }

    return clone;
}
```
