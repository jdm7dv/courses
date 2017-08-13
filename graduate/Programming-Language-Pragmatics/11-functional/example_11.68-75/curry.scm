;;; Examples 11.68, 11.69, and 11.75

(define fold
  (lambda (f i l)
    (if (null? l) i     ; i is commonly the identity element for f
        (f (car l) (fold f i (cdr l))))))

(define curried-plus (lambda (a) (lambda (b) (+ a b))))
((curried-plus 3) 4)                            ; 7
(define plus-3 (curried-plus 3))
(plus-3 4)                                      ; 7

(map (curried-plus 3) '(1 2 3))                 ; (4 5 6)

(define curry (lambda (f) (lambda (a) (lambda (b) (f a b)))))
(((curry +) 3) 4)                               ; 7
(define curried-plus2 (curry +))

(map (curried-plus2 3) '(1 2 3))                ; (4 5 6)

(define curried-fold
  (lambda (f)
    (lambda (i)
      (lambda (l)
        (if (null? l) i
            (f (car l) (fold f i (cdr l))))))))
(((curried-fold +) 0) '(1 2 3 4 5))             ; 15
