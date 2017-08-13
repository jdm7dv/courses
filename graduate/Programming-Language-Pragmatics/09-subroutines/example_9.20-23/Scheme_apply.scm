;; Example 9.21

(define apply-to-L
  (lambda (f l)
    (if (null? l) '()
        (cons (f (car l)) (apply-to-L f (cdr l))))))

(define inc (lambda (i) (+ i 1)))

(apply-to-L inc '(5 6 7 8 9 10))
