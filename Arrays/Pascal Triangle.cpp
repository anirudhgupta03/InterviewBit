//Method - 1
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

//Method - 2
vector<vector<int> > Solution::solve(int A) {

    vector<vector<int>> res;

    if(A == 0) return res;
    
    vector<int> temp;
    temp.push_back(1);

    res.push_back(temp);

    for(int i = 1; i < A; i++){
        vector<int> temp;
        temp.push_back(1);
        for(int j = 1; j <= res[i - 1].size() - 1; j++){
            temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}
