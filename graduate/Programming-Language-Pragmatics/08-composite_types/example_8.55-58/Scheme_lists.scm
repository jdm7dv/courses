;; Examples 8.55 and 8.56

(let ((l1 '(a b c d))
      (l2 '(a . (b . (c . (d . ())))))
      (l3 '(a . (b . (c . d)))))
    (display l1) (newline)
    (display l2) (newline)
    (display l3) (newline)
    (display (if (equal? l1 l2) "l1 equals l2" "l1 does not equal l2"))
    (newline)
    (display (if (equal? l1 l3) "l1 equals l3" "l1 does not equal l3"))
    (newline)
    (display (cdr (cdr (cdr l1))))
    (newline)
    (display (cdr (cdr (cdr l3))))
    (newline))

(display (cons 'a '(b)))          (newline)
(display (car '(a b)))            (newline)
; (display (car '()))             ;; error
(display (cdr '(a b c)))          (newline)
(display (cdr '(a)))              (newline)
; (display (cdr '()))             ;; error
    ;; use nil instead of () in Common Lisp
(display (append '(a b) '(c d)))  (newline)
