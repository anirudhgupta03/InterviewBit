bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i< arrive.size(); i++){
        v.push_back(make_pair(arrive[i],1));
    }
    for(int i = 0; i< depart.size(); i++){
        v.push_back(make_pair(depart[i],-1));
    }
    
    sort(v.begin(),v.end());
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        count += v[i].second;
        
        if(count > K)
            return false;
    }
    
    return true;
}
