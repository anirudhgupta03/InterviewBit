vector<int> Solution::solve(string A) {

    int alpha[26] = {0};
    vector<int> res;
    for(int i = A.size() - 1; i >= 0; i--){
        alpha[A[i] - 'a']++;
    }
    for(int i = 0; i < A.size(); i++){
        if(alpha[A[i] - 'a']){
            res.push_back(alpha[A[i] - 'a']);
            alpha[A[i] - 'a'] = 0;
        }
    }
    return res;
}
