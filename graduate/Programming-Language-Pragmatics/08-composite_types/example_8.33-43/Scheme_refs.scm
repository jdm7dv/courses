;; Examples 8.34 and 8.43 

(let
    ((t '(#\R (#\X ()()) (#\Y (#\Z ()()) (#\W ()())))))
    (car (cadr (caddr t))))     ;; Z

(let
    ((n '(#\N)))
    (display (cdr n))       ;; ()
    (newline)
    (set-cdr! n n)          ;; circular reference
    (display (cadddr n)))   ;; can dereference as often as we like!
