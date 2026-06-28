# Q3 Notes - Maximum Subarray Sum After Multiplier

Why the whole-array transform approach is wrong:

You tried:
- make full multiplied array
- make full divided array
- run Kadane on both

But the problem modifies exactly one subarray, not the whole array.

Counterexample:
nums = [10, -5, 10], k = 2

Best divide is to divide only [-5]:
[10, -2, 10]
max subarray = 18

If you divide the whole array:
[5, -2, 5]
max subarray = 8

So the operation must be handled inside Kadane using states:
- no operation yet
- currently inside modified subarray
- operation already ended
