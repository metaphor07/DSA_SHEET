# Maximum Product Subarray

## DP max/min
Track:
```text
maxProd = max product ending here
minProd = min product ending here
```

Why?
```text
Negative * negative can become maximum.
```

## Prefix-suffix
Scan from left and right.
Reset product to 1 after zero.

Memory hook:
```text
Negative flips max/min. Zero resets product.
```
