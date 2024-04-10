#lang racket
(define (sum-of-natural-numbers n)
  (if (= n 0)
      0
      (+ n (sum-of-natural-numbers (- n 1)))))

(define (main)
  (display "Enter the value of N: ")
  (define n (read))
  (display "The sum of first ")
  (display n)
  (display " natural numbers is: ")
  (display (sum-of-natural-numbers n))
  (newline))

(main)
