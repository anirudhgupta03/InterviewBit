//Ref: https://www.youtube.com/watch?v=KOD2BFauQbA&t=323s
vector<string> solve(int A){
    
    if(A == 1){
        vector<string> res;
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    
    vector<string> temp = solve(A-1);
    
    vector<string> re;
    
    for(int i = 0; i < temp.size(); i++){
        re.push_back("0" + temp[i]);
    }
    
    for(int i = temp.size() - 1; i >= 0; i--){
        re.push_back("1" + temp[i]);
    }
    
    return re;
}
int binToDec(string s){
    
    int n = 0;
    
    for(int i = 0; i < s.size(); i++){
        
        n += (1 << (s.size()-i-1))*(s[i] - '0');
    }
    return n;
}
vector<int> Solution::grayCode(int A) {
    
    string s = "";
    
    for(int i = 0; i < A; i++){
        s.push_back('0');
    }
    
    vector<string> res = solve(A);
    
    vector<int> ans;
    
    for(int i = 0; i < res.size(); i++){
        ans.push_back(binToDec(res[i]));
    }
    
    return ans;
}
