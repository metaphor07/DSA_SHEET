# Pattern: Reconstruct Itinerary

## Core idea
Tickets are directed edges.
Need to use every ticket exactly once.

That is Euler Path.

## Algorithm
```text
1. Build graph from source to destinations.
2. Store destinations in min heap for lexical order.
3. DFS from JFK.
4. While outgoing ticket exists, consume it and DFS.
5. Add airport after all outgoing tickets are used.
6. Reverse final route.
```

## Memory hook
Keep going until stuck.
When stuck, add airport.
Reverse answer.
