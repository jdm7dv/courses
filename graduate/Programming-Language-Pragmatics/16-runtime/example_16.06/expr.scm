;; Example 16.6

(let ((square_func (lambda (x) (* x x))))
  (square_func 3))

(let* ((square_tree '(lambda (x) (* x x)))
       (square_func2 (eval square_tree (scheme-report-environment 5))))
  (square_func2 3))
