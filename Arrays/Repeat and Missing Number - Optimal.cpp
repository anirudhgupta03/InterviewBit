vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long long sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < A.size(); i++){
        sum1 = sum1 + (long long)A[i];
        sum2 = sum2 + ((long long)A[i]*(long long)A[i]);
    }
    long long n = A.size();
    long long sum3 = (n*(n+1))/2;
    long long sum4 = (n*(n+1)*(2*n+1))/6;
    
    long long x = sum3-sum1;
    long long y = sum4-sum2;
    long long z;
    
    z = y/x;
    
    int r = (z-x)/2;
    int s = (z+x)/2;
    vector<int> v;
    v.push_back(r);
    v.push_back(s);
    return v;
    
}   
