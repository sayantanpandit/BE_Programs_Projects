(define (hcf a b) (cond ( (= (remainder a b) 0) b) (else ( hcf b (remainder a b)))))
