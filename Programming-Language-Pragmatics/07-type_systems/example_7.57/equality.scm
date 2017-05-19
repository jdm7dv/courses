;; Example 7.57

(eq? #t #t)           ;; #t
(eq? 'foo 'foo)       ;; #t
(eq? '(a b) '(a b))   ;; #f (created by separate cons-es)
(let ((p '(a b)))
  (eq? p p))          ;; #t (created by the same cons)
(eq? 2 2)             ;; unspecified (implementation dependent)
(eq? "foo" "foo")     ;; unspecified (implementation dependent)
