int Solution::solve(string A) {
    
    long long i = 0, C = 0, V = 0, ans = 0;
    
    
    while(i < A.size()){
        
        if(A[i] == 'a'|| A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
            while(i < A.size() && (A[i] == 'a'|| A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') ){
                ans = (ans + C)%(1000000007);
                V++;
                i++;
            }
        }
        else{
            while(i < A.size() && !(A[i] == 'a'|| A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')){
                ans = (ans + V)%(10000000007);
                C++;
                i++;
            }
        }
    }
    
    return ans%(1000000007);
}
