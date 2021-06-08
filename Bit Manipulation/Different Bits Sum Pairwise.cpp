//Brute Force
//Time Complexity - O(N^2)
//Space Complexity - O(1)
#define ll long long
int Solution::cntBits(vector<int> &A) {
    
    ll count = 0;
    int mod = 1e9 + 7;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = i; j < A.size(); j++){
            
            int val = A[i]^A[j];
            
            while(val){                 //Finding number of set bits
              val = val & (val - 1);  
              count++;
            }
        }
    }
    return (2*count)%mod;
}

//Optimal Approach
//Time Complexity - O(32*N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=L_fIn5TM3mM&t=611s
#define ll long long
int Solution::cntBits(vector<int> &A) {
    
    ll count = 0;
    int mod = 1e9 + 7;
    for(int i = 0; i < 32; i++){
        
        ll c = 0;
     
        for(int j = 0; j < A.size(); j++){
            
            if((A[j] & (1 << i)) != 0){
                c++;
            }
        }
        
        count += (c)*(A.size()-c);
    }
    return (2*count)%mod;
}
