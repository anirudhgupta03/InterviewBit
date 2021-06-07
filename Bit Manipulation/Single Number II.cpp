//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::singleNumber(const vector<int> &A) {
    
    unordered_map<int,int> myumap;
    
    for(int val: A){
        myumap[val]++;
    }
    
    for(auto x: myumap){
        
        if(x.second == 1){
            return x.first;
        }
    }
}
//Method - 2
//Ref: https://www.youtube.com/watch?v=_vSi_Wasm84
//Time Complexity - O(32*N)
//Space Complexity - O(1)
int Solution::singleNumber(const vector<int> &A) {
    
    int ele = 0;
    
    for(int i = 0; i <= 31; i++){
        
        int sum = 0;
        for(int j = 0; j < A.size(); j++){
            
            if(A[j] & (1 << i)){
                sum++;
            }
        }
        
        if(sum % 3 == 1){
            ele += 1 << i;
        }
    }
    return ele;
}
