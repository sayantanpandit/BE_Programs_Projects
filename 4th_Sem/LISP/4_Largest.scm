(define (sum n) (cond ( (= n 1) n) (else (+ n ( sum (- n 1))))))
