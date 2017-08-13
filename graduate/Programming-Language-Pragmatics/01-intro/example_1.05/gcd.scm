;;; Example 1.5 (Figure 1.2)

(define gcd2            ; 'gcd' is built-in to R5RS
  (lambda (a b) 
    (cond ((= a b) a) 
          ((> a b) (gcd2 (- a b) b)) 
          (else (gcd2 (- b a) a))))) 
