;;; Exercise 11.6

;; compute integer log, base 2
;; (number of bits in binary representation)
;; works only for positive integers
(define log2
  (lambda (n)
    (if (= n 1) 1 (+ 1 (log2 (quotient n 2))))))

;; find minimum element in a list
(define min2
  (lambda (l)
    (cond
      ((null? l) '())
      ((null? (cdr l)) (car l))
      (#t (let ((a (car l))
                (b (min2 (cdr l))))
            (if (< b a) b a))))))
