;; Exercise 3.13

(define A 
  (lambda() 
    (let* ((x 2) 
           (C (lambda (P) 
                (let ((x 4)) 
                  (P)))) 
           (D (lambda () 
                x)) 
           (B (lambda () 
                (let ((x 3)) 
                  (C D))))) 
      (B)))) 
