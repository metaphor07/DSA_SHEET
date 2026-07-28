# Q4 Dry Run

s = "abc"

Possible operations:
- remove "ab" => "c"
- remove "bc" => "a"
- do nothing => "abc"

Lexicographically smallest among:
"a", "c", "abc"

Answer = "a"

Why "a" < "abc"?
Because "a" is a prefix of "abc" and shorter.
