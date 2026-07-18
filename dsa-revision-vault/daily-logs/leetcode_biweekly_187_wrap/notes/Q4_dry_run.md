# Q4 Dry Run

source = "hello"
target = "world"

rules:
"he" -> "wo", cost 3
"llo" -> "rld", cost 4

dp[0] = 0

At i = 0:
source segment "he" matches pattern "he"
target segment "wo" matches replacement "wo"
dp[2] = 3

At i = 2:
source segment "llo" matches pattern "llo"
target segment "rld" matches replacement "rld"
dp[5] = 7

Answer = 7.
