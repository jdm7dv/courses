;;; Example 11.20 (Figures 11.1 and 11.2)

(define simulate
  (lambda (dfa input)
    (letrec ((helper  ; note that helper is tail recursive,
              ; but builds the list of moves in reverse order
              (lambda (moves d2 i)
                (let ((c (current-state d2)))
                  (if (null? i) (cons c moves)
                      (helper (cons c moves) (move d2 (car i)) (cdr i)))))))
      (let ((moves (helper '() dfa input)))
        (reverse (cons (if (is-final? (car moves) dfa)
                           'accept 'reject) moves))))))

;; access functions for machine description:
(define current-state car)
(define transition-function cadr)
(define final-states caddr)
(define is-final? (lambda (s dfa) (memq s (final-states dfa))))

(define move
  (lambda (dfa symbol)
    (let ((cs (current-state dfa)) (trans (transition-function dfa)))
      (list
       (if (eq? cs 'error)
           'error
           (let ((pair (assoc (list cs symbol) trans)))
             (if pair (cadr pair) 'error))) ; new start state
       trans                                ; same transition function
       (final-states dfa)))))               ; same final states

(define zero-one-even-dfa
 '(q0                                                 ; start state
   (((q0 0) q2) ((q0 1) q1) ((q1 0) q3) ((q1 1) q0)   ; transition fn
    ((q2 0) q0) ((q2 1) q3) ((q3 0) q1) ((q3 1) q2))
   (q0)))                                             ; final states

(define test1
  (lambda ()
    (simulate
     zero-one-even-dfa  ; machine description
     '(0 1 1 0 1))))    ; input string

(define test2
  (lambda ()
    (simulate
     zero-one-even-dfa  ; machine description
     '(0 1 0 0 1 0))))  ; input string
