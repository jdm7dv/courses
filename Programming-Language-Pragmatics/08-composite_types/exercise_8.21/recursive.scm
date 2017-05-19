;; Exercise 8.21

(define foo
  (lambda ()
    (letrec ((a (lambda(f) (if f #\A b)))
             (b (lambda(f) (if f #\B c)))
             (c (lambda(f) (if f #\C a))))
      a)))

((foo) #t)
(((foo) #f) #t)
((((foo) #f) #f) #t)
(((((foo) #f) #f) #f) #t)
