bool cmp(pair<pair<int,string>,int> p1, pair<pair<int,string>,int> p2){
    
    if(p1.second == p2.second){
        return p1.first.first < p2.first.first;
    }
    return p1.second > p2.second;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    
    unordered_map<string,int> myumap;
    
    int l = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '_'){
            myumap[A.substr(l,i-l)]++;
            l = i + 1;
        }
    }
    myumap[A.substr(l,A.size()-l)]++;
    
    vector<pair<pair<int,string>,int>> v;
    
    for(int i = 0; i < B.size(); i++){
        
        string C = B[i];
        l = 0;
        int count = 0;
        for(int j = 0; j < C.size(); j++){
            if(C[j] == '_'){
                if(myumap.find(C.substr(l,j-l)) != myumap.end()){
                    count++;
                }
                l = j + 1;
            }
        }
        if(myumap.find(C.substr(l,C.size()-l)) != myumap.end()){
            count++;
        }
        v.push_back({{i,C},count});
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> ans;
    
    for(int i = 0; i < v.size(); i++){
        ans.push_back(v[i].first.first);
    }
    return ans;
}
