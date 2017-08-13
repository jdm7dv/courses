;; Example 16.7
;; The easiest way to run this is to actually type it into the
;; read-eval-print loop.  You can also feed it in via redirection
;; ("cmucl < compile.cl").  If you want to actually run it from the file
;; ("cmucl -load compile.cl"), you'll need to add output statements.

(defun square (x) (* x x))  ; outermost level function declaration
(square 3)                  ; 9
(compile 'square)
(square 3)                  ; also 9 (but faster :-)
