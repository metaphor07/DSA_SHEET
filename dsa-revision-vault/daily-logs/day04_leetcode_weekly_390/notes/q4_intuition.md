# Q4 Intuition

For every query word, find the index of the word in wordsContainer with the longest common suffix.

Suffix matching from the end becomes prefix matching if we reverse the words.

Example:
container = abcd
query = xbcd

common suffix = bcd

Reversed:
dcba
dcbx

Now common suffix becomes common prefix.

Build a trie using reversed container words.

At every trie node, store the best index among all words passing through that node.

Best index means:
1. smaller word length
2. if same length, smaller index

For a query:
walk in the trie from the last character to the first.
The deepest node reached represents the longest suffix match.
Return the stored best index at that node.

If no character matches, return trie root's best index.
That represents the globally shortest word, with smallest index on tie.
