;;; O(N)
(define cons-fin
  (lambda (x lst)
    (if (null? lst)
        (cons x '())
        (cons (car lst)
              (cons-fin x (cdr lst))))))

(define dup
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst)
              (cons (car lst)
                    (dup (cdr lst)))))))