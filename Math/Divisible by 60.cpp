/*For a number to be divisible by a composite number, it should be divisible 
by the individual prime numbers raised to their highest powers.
Here, 60 = 4 * 5 * 3.
Now, we have to make sure that the number is divisible by 3, 4, 5.
For, a number to be divisible by 5, the last digit should be either 0 or 5.
For, a number to be divisible by 4, the last two digits should be divisible by 4.
Hence, here for a number to be divisble by 4 & 5, the last digits should be 0, 
and the second last digits should be even.

Next, for a number to be divisible by 3, the sum of digits should be divisible by 3.
Hence, if the given array sum is divisible by 3 and contains 0 and an another even digit, 
then there exists a permutation which is divisible by 60.
*/
int Solution::divisibleBy60(vector<int> &A) {
    if(A.size() == 1 && A[0] == 0){
        return true;
    }
    bool zero = false, even = false;
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 0){
            zero = true;
        }
        else if(A[i] % 2 == 0){
            even = true;
        }
        sum += A[i];
    }
    if(sum % 3 == 0 && zero && even) return 1;
    return 0;
}
