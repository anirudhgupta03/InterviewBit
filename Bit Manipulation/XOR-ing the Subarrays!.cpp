//As we know a ⊕ a = 0. When we write all substrings, we have to check how many numbers occur an even number of times and how many numbers occur an odd number of times. 
//If the list is 0 indexed, the number at ith index will occur (i + 1) * (N - i) times.
//If N is even, either i + 1 or N - i will be even. Each number will occur an even number of times, and the answer will be 0 .
//If N is odd and i is even, the product of the XOR will be odd. In that case, the answer is the XOR of the even indexed elements.

int Solution::solve(vector<int> &A) {
    
    if(A.size() % 2 == 0){
        return 0;
    }
    else{
        int xor_sum = 0;
        for(int i = 0; i < A.size(); i++){
            
            if(i % 2 == 0){
                xor_sum ^= A[i];
            }
        }
        return xor_sum;
    }
}
