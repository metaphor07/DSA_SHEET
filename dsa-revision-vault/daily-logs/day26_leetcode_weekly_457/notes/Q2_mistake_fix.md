# Q2 Mistake Fix

Wrong idea:
Always return the smallest online node in the component.

Correct rule:
If requested node itself is online, return that node.

Only when requested node is offline, return the smallest online node from the same component.

Key check:
if (component[root].count(node)) return node;
else return *component[root].begin();
