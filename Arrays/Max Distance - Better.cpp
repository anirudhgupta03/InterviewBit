int Solution::maximumGap(const vector<int> &A) {
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i < A.size(); i++){
        v.push_back(make_pair(A[i],i));
    }
    
    sort(v.begin(),v.end());
    
    int i = v[v.size()-1].second ,ans = 0;
    for(int j = v.size()-2; j >= 0; j--){
        ans = max(ans,i - v[j].second);
        i = max(v[j].second,i);
    }
    return ans;
}
