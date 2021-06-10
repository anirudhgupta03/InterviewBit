//Method - 1
string Solution::solve(string A) {
    
    string res, temp;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == ' ' && temp.size()!= 0){
            res = temp + " " + res;
            temp.clear();
        }
        else if(A[i] != ' '){
            temp.push_back(A[i]);
        }
    }
    if(temp.size() != 0)
    res = temp + " " + res;
    res.pop_back();
    return res;
}

//Method - 2
string Solution::solve(string A) {
    
    stringstream X(A);
    
    string s, p;
    while(X>>s){
        p = ' ' + s + p ;
    }
    
    int i = 0;
    while(p[i] == ' '){
        i++;
    }
    string ans;
    for(int j = i; j < p.size(); j++){
        ans.push_back(p[j]);
    }
    return ans;
}
