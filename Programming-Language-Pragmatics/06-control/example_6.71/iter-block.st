" Example 6.71
|
| Note that GNU Smalltalk syntax differs from that used in the book.
| In particular, assignment uses :=
| Note also that:
|   Comments are double-quoted strings.
|   The printNl message is the standard way to make an object print itself.
"

sum := 0.
1 to: 100 by: 2 do:
    [:i | sum := sum + i].
sum printNl.
