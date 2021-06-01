//Ref: https://www.youtube.com/watch?v=_DtZIPUt8jo&t=83s
bool cmp(pair<int,int> p1,pair<int,int> p2){
    return p1.first > p2.first;
}
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i < n; i++){
        v.push_back({A[i],B[i]});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    vector<int> ans;
    
    for(int i = 0; i < n; i++){
        ans.insert(ans.begin()+v[i].second,v[i].first);
    }
    return ans;
}
