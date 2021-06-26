//Method - 1
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    map<vector<int>,vector<int>> m;
    
    for(int i = 0; i < A.size(); i++){
        
        vector<int> alpha(26,0);
        
        for(int j = 0;  j < A[i].size(); j++){
            alpha[A[i][j]-97]++;
        }
        
        m[alpha].push_back(i+1);
    }
    
    vector<vector<int>> res;
    
    map<vector<int>,vector<int>> :: iterator it;
    
    for(it = m.begin(); it != m.end(); it++){
        res.push_back(it->second);
    }
    return res;
}

//Method - 2
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    unordered_map<string,vector<int>> umap;
    
    vector<vector<int>> res;
    
    for(int i = 0; i < A.size(); i++){
        
        string s = A[i];
        sort(s.begin(),s.end());
        
        umap[s].push_back(i + 1);
    }
    
    for(auto it: umap){
        res.push_back(it.second);
    }
    
    return res;
}
