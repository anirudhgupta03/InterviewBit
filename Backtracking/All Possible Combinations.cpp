void solve(int ind, vector<string> &A, string &temp, vector<string> &res){

    if(ind == A.size()){
        res.push_back(temp);
        return;
    }
    for(int i = 0; i < A[ind].size(); i++){
        temp.push_back(A[ind][i]);
        solve(ind + 1, A, temp, res);
        temp.pop_back();
    }
}
vector<string> Solution::specialStrings(vector<string> &A) {

    vector<string> res;
    string temp;
    solve(0, A, temp, res);
    return res;
}
