;; Example 3.10

(let ((A 1))        ; outer scope, with A defined to be 1
    (let ((A 2)     ; inner scope, with A defined to be 2
          (B A))    ;               and B defined to be A
        B))         ; return the value of B
