;; Exercise 11.5

(define unique
  (lambda (L)
    (cond
     ((null? L) L)
     ((null? (cdr L)) L)
     ((eqv? (car L) (car (cdr L))) (unique (cdr L)))
     (else (cons (car L) (unique (cdr L)))))))
