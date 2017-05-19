;; Example 7.45

;; NB: 'min' is predefined

(define min2 (lambda (a b) (if (< a b) a b)))

(min2 123 456)
(min2 3.14159 2.71828)
(min2 "abc" "def")  ;; error
