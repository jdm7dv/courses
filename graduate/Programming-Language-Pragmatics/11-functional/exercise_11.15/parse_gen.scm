;;; Exercise 11.15

;; sample input:
(define calc-gram
  '(("program"  ("stmt_list" "$$"))
    ("stmt_list" ("stmt" "stmt_list") ())
    ("stmt"  ("id" ":=" "expr") ("read" "id") ("write" "expr"))
    ("expr"  ("term" "term_tail"))
    ("term"  ("factor" "factor_tail"))
    ("term_tail" ("add_op" "term" "term_tail") ())
    ("factor_tail" ("mult_op" "factor" "FT") ())
    ("add_op" ("+") ("-"))
    ("mult_op" ("*") ("/"))
    ("factor"  ("id") ("number") ("(" "expr" ")"))))

;; corresponding output:
(define parse-table
  '(("program" (("$$" "id" "read" "write") ("stmt_list" "$$")))
    ("stmt_list" (("id" "read" "write") ("stmt" "stmt_list")) (("$$") ()))
    ("stmt"
     (("id") ("id" ":=" "expr"))
     (("read") ("read" "id"))
     (("write") ("write" "expr")))
    ("expr" (("(" "id" "number") ("term" "term_tail")))
    ("term" (("(" "id" "number") ("factor" "factor_tail")))
    ("term_tail"
     (("+" "-") ("add_op" "term" "term_tail"))
     (("$$" ")" "id" "read" "write") ()))
    ("factor_tail"
     (("*" "/") ("mult_op" "factor" "factor_tail"))
     (("$$" ")" "+" "-" "id" "read" "write") ()))
    ("add_op" (("+") ("+")) (("-") ("-")))
    ("mult_op" (("*") ("*")) (("/") ("/")))
    ("factor"
     (("id") ("id"))
     (("number") ("number"))
     (("(") ("(" "expr" ")")))))
