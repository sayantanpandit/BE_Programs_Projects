(define (fibo x) (cond ((= x 1) 0) ((= x 2) 1) (else (+ (fibo (- x 1)) (fibo (- x 2))))))
