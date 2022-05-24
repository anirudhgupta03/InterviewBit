long Solution::solve(int A, int B) {

    long a = A, b = B;

    return (a*b)/__gcd(a,b);
}
