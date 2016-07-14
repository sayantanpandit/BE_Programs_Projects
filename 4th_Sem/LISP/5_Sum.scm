(define (largest l large) (cond ((= (length (cdr l)) 0) (cond ((< (car l) large) large) (else (car l)))) ((< large (car l)) (largest (cdr l) (car l))) (else (largest (cdr l) large))))
