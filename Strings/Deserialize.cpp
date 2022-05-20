vector<string> Solution::deserialize(string A) {

    vector<string> res;
    string s;
    for(int i = 0; i < A.size(); i++){
        if(isdigit(A[i])){
            while(isdigit(A[i])) i++;
            res.push_back(s);
            s = "";
        }
        else{
            s.push_back(A[i]);
        }
    }
    return res;
}
