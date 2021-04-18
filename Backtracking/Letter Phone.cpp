void solve(int ind, string A, vector<string> &v, string &temp, map<int,string> &m){
    
    if(temp.size() == A.size()){
        v.push_back(temp);
        return;
    }
    for(int j = 0; j < m[A[ind]-48].size(); j++){
        temp.push_back(m[A[ind]-48][j]);
        solve(ind+1,A,v,temp,m);
        temp.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) {
    
    map<int,string> m;
    
    m[0] = "0";
    m[1] = "1";
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    
    vector<string> v;
    string temp;
    
    solve(0,A,v,temp,m);
    
    return v;
}
