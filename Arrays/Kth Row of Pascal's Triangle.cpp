//Brute Force Approach
//Time Complexity - O(A^2)
//Space Complexity - O(A^2)
vector<int> Solution::getRow(int A) {
    
    vector<vector<int>> v1;
    
    for(int i = 0; i <= A; i++){
        
        vector<int> v2;
        
        for(int j = 0; j <= i; j++){
            
            if(j == 0){
                v2.push_back(1);
            }
            else if(j == i){
                v2.push_back(1);
            }
            else{
                v2.push_back(v1[i-1][j] + v1[i-1][j-1]);
            }
        }
        
        v1.push_back(v2);
    }
    
    return v1[A];
}

//Method - 2
//Time Complexity - O(A^2)
//Space Complexity - O(A)
vector<int> Solution::getRow(int A) {
    
    vector<int> res(A+1);
    
    for(int i = 0; i <= A; i++){
        
        for(int j = i; j >= 0; j--){
            
            if(j == 0 || j == i){
                res[j] = 1;
            }
            else{
                res[j] = res[j] + res[j-1];
            }
        }
    }
    return res;
}

//Method - 3
//Time Complexity - O(A)
//Space Complexity - O(A)
vector<int> Solution::getRow(int A) {
    
    vector<int> res(A+1);
    res[0] = 1;
    
    for(int i = 1; i < A + 1; i++){
        res[i] = res[i-1]*(A-i+1);
        res[i] /= i;
    }
    return res;
}
