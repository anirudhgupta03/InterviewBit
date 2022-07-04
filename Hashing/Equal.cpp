//Method - 1
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

//Method - 2
vector<int> Solution::equal(vector<int> &A) {
    
    int a1 = INT_MAX, b1 = INT_MAX, c1 = INT_MAX, d1 = INT_MAX;
    
    unordered_map<int,vector<int>> umap;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = i + 1; j < A.size(); j++){
            int sum = A[i] + A[j];
            if(umap.find(sum) != umap.end()){
                
                int A1 = umap[sum][0], B1 = umap[sum][1], C1 = i, D1 = j;
                
                if(A1 < a1 || A1 == a1 && B1 < b1 || A1 == a1 && B1 == b1 && C1 < c1 || A1 == a1 && B1 == b1 && C1 == c1 && D1 < d1){
                    
                    if(A1 < C1 && B1 != D1 && B1 != C1){
                        a1 = A1;
                        b1 = B1;
                        c1 = C1;
                        d1 = D1;
                    }
                }
            }
            else{
                umap[sum] = {i,j};
            }
        }
    }
    if(a1 != INT_MAX){
        vector<int> res = {a1, b1, c1, d1};
        return res;
    }
    return {};
}
