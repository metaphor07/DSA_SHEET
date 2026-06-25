# Q3 Intuition

Use hashmap + max heap.

Hashmap:
currentFreq[id] = current active frequency

Max heap:
stores {frequency, id}

Problem:
Priority queue cannot update old entries directly.

So whenever frequency changes, push the new pair.
Old pairs remain in heap temporarily.

Before answering, remove outdated heap entries:

while pq.top().frequency != currentFreq[pq.top().id]:
    pq.pop()

This is called lazy deletion.
