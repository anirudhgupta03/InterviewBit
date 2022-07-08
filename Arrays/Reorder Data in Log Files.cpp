bool cmp(pair<string,string> &p1, pair<string,string> &p2){
    
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
vector<string> Solution::reorderLogs(vector<string> &A) {
    
    vector<pair<string,string>> letterLogs;
    vector<string> digitLogs;
    
    for(int i = 0; i < A.size(); i++){
        string identifier;
        for(int j = 0; j < A[i].size(); j++){
            if(A[i][j] == '-'){
                if(isdigit(A[i][j + 1])){
                    digitLogs.push_back(A[i]);
                }
                else{
                    letterLogs.push_back({identifier, A[i].substr(j + 1)});
                }
                break;
            }
            else{
                identifier.push_back(A[i][j]);
            }
        }
    }
    sort(letterLogs.begin(), letterLogs.end(), cmp);
    vector<string> res;
    for(auto &x: letterLogs){
        res.push_back(x.first + "-" + x.second);
    }
    for(auto &x: digitLogs){
        res.push_back(x);
    }
    return res;
}
