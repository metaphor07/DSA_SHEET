# Pattern: Target Sum

## Transform
```text
positiveSum - negativeSum = target
positiveSum + negativeSum = total
positiveSum = (total + target) / 2
```

Then count subsets with sum positiveSum.

## Checks
```text
if abs(target) > total return 0
if (total + target) % 2 != 0 return 0
```

## Memory hook
Target Sum becomes count subset sum.
