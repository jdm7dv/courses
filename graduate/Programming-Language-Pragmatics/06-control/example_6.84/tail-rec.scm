;; Example 6.84

(define summation
  (lambda (f low high)
    (if (= low high)
        (f low)                                       ; then part
        (+ (f low) (summation f (+ low 1) high)))))   ; else part

(define summation2
  (lambda (f low high subtotal)
    (if (= low high)
        (+ subtotal (f low))
        (summation2 f (+ low 1) high (+ subtotal (f low))))))

(define summation3
  (lambda (f low high)
    (letrec ((sum-helper
              (lambda (low subtotal)
                (let ((new_subtotal (+ subtotal (f low))))
                  (if (= low high)
                      new_subtotal
                      (sum-helper (+ low 1) new_subtotal))))))
      (sum-helper low 0))))

(define square (lambda (n) (* n n)))

(summation square 1 10)
(summation2 square 1 10 0)
(summation3 square 1 10)
