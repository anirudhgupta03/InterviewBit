vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int> > v2;
    
    for(int i = 1; i <= A; i++){
        
        vector<int> v3;
        
        for(int j = 0; j < i; j++){
            if(j == 0){
                v3.push_back(1);
            }
            else if(j == i-1){
                v3.push_back(1);
            }
            else{
                v3.push_back(v2[i-2][j] + v2[i-2][j-1]);
            }
        }
        v2.push_back(v3);
    }
    
    return v2;
}
