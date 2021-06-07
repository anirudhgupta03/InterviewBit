//Method - 1
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
//Method - 2
//Time Complexity - O(N)
//Space Complexity -O(1)
#define ll long long
int Solution::solve(string A) {
    
    int n = A.size();
    
    int mod = 1e9 + 7;
    
    ll count = 0,ans = 0;
    
    for(int i = n - 1; i >= 0; i--){
        
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
            count++;
        }
        else{
            ans += count;
        }
    }

    count = 0;
    
    for(int i = n - 1; i >= 0; i--){
        
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
            ans += count;
        }
        else{
            count++;
        }
    }
    
    return ans%mod;
}
//Method - 3
//Time Complexity - O(N)
//Space Complexity -O(1)
#define ll long long
int Solution::solve(string A) {
    
    int n = A.size();
    
    int mod = 1e9 + 7;
    
    ll vow = 0, cons = 0,ans = 0;
    
    for(int i = n - 1; i >= 0; i--){
        
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
            vow++;
            ans += cons;
        }
        else{
            cons++;
            ans += vow;
        }
    }
    return ans%mod;
}
