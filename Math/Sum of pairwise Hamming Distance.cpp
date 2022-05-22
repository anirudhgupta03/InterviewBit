int Solution::hammingDistance(const vector<int> &A) {

    int mod = 1e9 + 7, sum = 0;

    for(int i = 31; i >= 0; i--){

        int count = 0;

        for(int j = 0; j < A.size(); j++){
            if((A[j] & (1 << i))){
                count++;
            }
        }
        sum = (sum + 2*(count*(A.size() - count))%mod)%mod;
    }
    return sum;
}
