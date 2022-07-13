int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    vector<int> freq(n + 1, 0);
    
    for(auto &x: A){
        freq[x]++;
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        count += freq[i]/2;
    }
    return count;
}
