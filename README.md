# InterviewBit
This repository maintains the solution to the InterviewBit problems.

Q - Minimum characters to be added at front to make string palindrome<br/>
Ref: https://www.youtube.com/watch?v=c4akpqTwE5g<br/>
Algo - KMP

Q - Find Nth Fibonacci<br/>
Ref: https://www.youtube.com/watch?v=oBH9dH6KGLM<br/>
Algo - Matrix Exponentiation<br/>
![Matrix Exponentiation](https://github.com/anirudhgupta03/InterviewBit/blob/main/Matrix%20Exponentiation.jpg)

Properties of modulo
1) (a + b) mod m = ((a mod m) + (b mod m)) mod m
2) (a x b) mod m = ((a mod m) x (b mod m)) mod m
3) (a - b) mod m = ((a mod m) - (b mod m) + m) mod m
4) Here comes a little problem to handle division modulo.

NOTE THAT : (a / b) mod m is not equal to (a mod m/ b mod m) mod m.

(a / b) mod m = (a mod m * inv(b) mod m + m) mod m, where inv(b) is inverse of b.

Now, how to calculate inv(b) mod m.

Using Fermat's little Theorem,

inv(b) mod m = b^-1 mod m = b^(m-2) mod m, only if b and m are COPRIME.

If m is prime(like, 10^9+7), then above formula will work.

So, (a / b) mod m = (a*b^(m-2)) mod m, if b and m are COPRIME.

Ref1: https://www.youtube.com/watch?v=Gd9w8m-klho
Ref2: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
