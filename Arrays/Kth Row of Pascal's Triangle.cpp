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
