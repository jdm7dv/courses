;; Example 6.88

(define naturals
  (letrec ((next (lambda (n) (cons n (delay (next (+ n 1)))))))
    (next 1)))
(define head car)
(define tail (lambda (stream) (force (cdr stream))))

(head naturals)               ; 1
(head (tail naturals))        ; 2
(head (tail (tail naturals))) ; 3
