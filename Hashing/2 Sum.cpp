//Method - 1
bool cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i < A.size(); i++){
        v.push_back({A[i],i});
    }
    
    sort(v.begin(),v.end());
    
    int l = 0, r = v.size() - 1;
    
    int p1 = -1, p2 = INT_MAX;
    
    while(l < r){
        
        if(v[l].first + v[r].first == B){
            
            int pos1 = v[l].second;
            int pos2 = v[r].second;
            
            if(pos1 > pos2){
                swap(pos1,pos2);
            }
            
            if(pos2 < p2){
                p1 = pos1;
                p2 = pos2;
            }
            else if(pos2 == p2){
                if(pos1 < p1){
                    p1 = pos1;
                }
            }
            r--;
        }
        else if(v[l].first + v[r].first < B){
            l++;
        }
        else{
            r--;
        }
    }
    
    vector<int> res;
    if(p1 == -1){
        return res;
    }
    
    res.push_back(p1+1);
    res.push_back(p2+1);
    return res;
}

//Method - 2
//Time Complexity - O(N^2)
//Space Complexity - O(N)
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    unordered_map<int,vector<int>> umap;
    
    for(int i = 0; i < A.size(); i++){
        umap[A[i]].push_back(i);
    }
    
    int ind1 = INT_MAX, ind2 = INT_MAX;
    
    for(int i = 0; i < A.size(); i++){
        
        if(umap.find(B-A[i]) != umap.end()){
            
            for(int j = 0; j < umap[B-A[i]].size(); j++){
                
                if(i == umap[B-A[i]][j]){
                    continue;
                }
                int i1 = min(i,umap[B-A[i]][j]);
                int i2 = max(i,umap[B-A[i]][j]);
                
                if(i2 < ind2){
                    ind2 = i2;
                    ind1 = i1;
                }
                else if(i2 == ind2){
                    if(i1 < ind1){
                        ind1 = i1;
                    }
                }
            }
        }
    }
    
    vector<int> res;
    if(ind1 != INT_MAX){
        res.push_back(ind1+1);
        res.push_back(ind2+1);
    }
    return res;
}

//Method - 3
//Optimal Approach
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    unordered_map<int,int> umap;
    vector<int> res;
    
    for(int i = 0; i < A.size(); i++){
        
        if(umap.find(B-A[i]) != umap.end()){
            res.push_back(umap[B-A[i]]);
            res.push_back(i+1);
            return res;
        }
        if(umap.find(A[i]) == umap.end()){
            umap[A[i]] = i + 1;
        }
    }
    return res;
}
