# Day 02 Mistake Log

## Reverse Integer
Check overflow before `rev = rev * 10 + digit`.

## Self Dividing Number
Check `digit == 0` before using modulo.

## Digit Loop
Always write `n /= 10` inside the loop.
