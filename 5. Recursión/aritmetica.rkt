;;; (define ... (lambda ...))
;;; (if ...)

(define inc
  (lambda (x)
    (+ x 1)))

(define dec
  (lambda (x)
    (- x 1)))

(define zero? ; Predicado: función que devuelve un valor booleano
  (lambda (x)
    (equal? x 0)))

(define add
  (lambda (a b)
    (if (zero? a)
        b
        (inc (add (dec a) b)))))

(define sub
  (lambda (a b)
    (if (zero? b)
        a
        (dec (sub a (dec b))))))

(define mul
  (lambda (a b)
    (if (zero? a)
        a
        (add (mul (dec a) b) b))))
