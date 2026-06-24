# Pattern: Lowest Common Ancestor in BST

## Use BST property
If both target nodes are smaller than current node, go left.  
If both target nodes are greater than current node, go right.  
Otherwise current node is the split point and therefore LCA.
