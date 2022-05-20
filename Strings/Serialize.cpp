string Solution::serialize(vector<string> &A) {

    string res;

    for(int i = 0; i < A.size(); i++){
        res += A[i] + to_string(A[i].size()) + "~";
    }
    return res;
}
