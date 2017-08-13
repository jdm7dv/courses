;;; Examples 11.64, 11.65, and 10.67

(map * '(2 4 6) '(3 5 7))                       ; (6 20 42)

(define fold
  (lambda (f i l)
    (if (null? l) i     ; i is commonly the identity element for f
      (f (car l) (fold f i (cdr l))))))

(fold + 0 '(1 2 3 4 5))                         ; 15
(fold * 1 '(1 2 3 4 5))                         ; 120

(define total (lambda (l) (fold + 0 l)))
(total '(1 2 3 4 5))                            ; 15

(define total-all (lambda (l) (map total l)))
(total-all '((1 2 3 4 5)
             (2 4 6 8 10)
             (3 6 9 12 15)))                    ; (15 30 45)

(define make-double (lambda (f) (lambda (x) (f x x))))
(define twice (make-double +))
(define square (make-double *))

(twice 3)                                       ; 6
(square 6)                                      ; 36
