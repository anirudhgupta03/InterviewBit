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
