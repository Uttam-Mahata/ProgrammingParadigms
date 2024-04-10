#lang racket
(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (hcf n1 n2)
  (if (= n2 0)
      n1
      (hcf n2 (remainder n1 n2))))

; Main function to compute HCF of two numbers
(define (main)
  (display "Enter first number (N1): ")
  (define n1 (read))
  (display "Enter second number (N2): ")
  (define n2 (read))
  (if (< n1 n2)
      (begin
        (display "Error: N1 should be greater than or equal to N2.")
        (newline))
      (begin
        (display "HCF of ")
        (display n1)
        (display " and ")
        (display n2)
        (display " is ")
        (display (gcd n1 n2))
        (newline))))

(main)
