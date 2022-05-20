vector<int> Solution::solve(string A) {
    vector<int> alpha(26, 0);
    for(int i = 0; i < A.size(); i++){
        alpha[A[i] - 'a']++;
    }
    return alpha;
}
