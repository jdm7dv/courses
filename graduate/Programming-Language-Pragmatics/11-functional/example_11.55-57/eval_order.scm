;;; Examples 11.55, 11.56, and 11.57

(define double (lambda (x) (+ x x)))

(double (* 3 4))                                ; 24

(define switch
  (lambda (x a b c)
    (cond ((< x 0) a)
          ((= x 0) b)
          ((> x 0) c))))

(switch -1 (+ 1 2) (+ 2 3) (+ 3 4))             ; 3

(define f
  (lambda ()
    (let ((done #f)                     ; memo initially unset
          (memo '())
          (code (lambda () (* 3 4))))
      (if done memo                     ; if memo is set, return it
          (begin
            (set! memo (code))          ; remember value
            (set! done #t)              ; note that we set it
            memo)))))                   ; and return it

(double (f))                            ; 24
