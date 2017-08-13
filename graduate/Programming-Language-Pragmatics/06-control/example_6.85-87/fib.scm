;; Examples 6.85 and 6.87

(define fib
  (lambda (n)
    (cond ((= n 0) 1)
          ((= n 1) 1)
          (#t (+ (fib (- n 1)) (fib (- n 2)))))))

(define fib2
  (lambda (n)
    (letrec ((fib-helper
              (lambda (f1 f2 i)
                (if (= i n)
                    f2
                    (fib-helper f2 (+ f1 f2) (+ i 1))))))
      (fib-helper 0 1 0))))

;; compare the speed of the following:
(fib2 30)
(fib 30)
