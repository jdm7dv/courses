;; Example 3.32

(define plus-x
  (lambda (x)
    (lambda (y) (+ x y))))

(let ((f (plus-x 2)))
  (f 3))                ; returns 5
