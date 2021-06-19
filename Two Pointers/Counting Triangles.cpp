//Method - 1
//TLE
//Time Complexity - O(N^3)
//Space Complexity - O(1)
#define ll long long
int Solution::nTriang(vector<int> &A) {
    
    int mod = 1e9 + 7;
    
    int n = A.size();
    
    if(n < 3){
        return 0;
    }
    ll count = 0;
    
    sort(A.begin(),A.end());
    
    for(int i = 0; i <= A.size() - 3; i++){
        
        for(int j = i + 1; j <= A.size() - 2; j++){
            
            int s = A[i] + A[j];
            
            int k = j + 1;
            
            while(k < A.size()){
                
                if(A[i] + A[j] > A[k]){
                    count++;
                }
                else{
                    break;
                }
                
                k++;
            }
        }
    }
    return count%mod;
}

//Method - 2
//Time Complexity - O(N^2logN)
//Space Complexity - O(1)
#define ll long long
int Solution::nTriang(vector<int> &A) {
    
    int mod = 1e9 + 7;
    
    int n = A.size();
    
    if(n < 3){
        return 0;
    }
    ll count = 0;
    
    sort(A.begin(),A.end());
    
    for(int i = 0; i <= A.size() - 3; i++){
        
        for(int j = i + 1; j <= A.size() - 2; j++){
            
            int s = A[i] + A[j];
            
            count += lower_bound(A.begin()+j+1,A.end(),s) - (A.begin() + j + 1);
        }
    }
    return count%mod;
}

//Method - 3
//Optimal Approach
//Time Complexity - O(N^2)
//Space Complexity - O(1)
int Solution::nTriang(vector<int> &A) {
    
    int mod = 1e9 + 7;
    
    sort(A.begin(),A.end());
    
    int count = 0;
    
    int n = A.size();
    
    for(int i = n - 1; i>=0; i--){
        
        int l = 0, r = i-1;
        
        while(l < r){
            if(A[l] + A[r] > A[i]){
                count = (count + r - l)%mod;
                r--;
            }
            else{
                l++;
            }
        }
    }
    return count;
}
