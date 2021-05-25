vector<int> Solution::equal(vector<int> &A) {
    
    int n = A.size();
    
    unordered_map<int,pair<int,int>> m;
    
    vector<vector<int>> res;
    
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            
            if(m.find(A[i]+A[j]) != m.end()){
                vector<int> temp;
                
                int a1 = m[A[i]+A[j]].first, b1 = m[A[i]+A[j]].second;
                
                int c1 = i, d1 = j;
                
                if(a1 < c1 && b1 != c1 && b1 != d1){
                    temp.push_back(a1);
                    temp.push_back(b1);
                    temp.push_back(c1);
                    temp.push_back(d1);
                    res.push_back(temp);
                }
            }
            else{
                m[A[i]+A[j]] = {i,j};
            }
        }
    }
    sort(res.begin(),res.end());
    
    vector<int> ans;
    if(res.size() == 0){
        return ans;
    }
    ans = res[0];
    return ans;
}
