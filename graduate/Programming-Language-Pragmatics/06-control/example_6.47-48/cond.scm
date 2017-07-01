;; Example 6.48 (in Scheme)

(define compare
  (let ((B 2)
        (C 3)
        (D 5))
    (lambda (A)
      (cond
       ((= A B)
        "matches B")
       ((= A C)
        "matches C")
       ((= A D)
        "matches D")
       (else                    ; Scheme uses 'else' instead of 'T'
        "doesn't match")))))
