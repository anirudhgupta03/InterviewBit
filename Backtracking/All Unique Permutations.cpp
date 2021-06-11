//https://www.interviewbit.com/problems/all-unique-permutations/?ref=similar_problems
void solve(int idx, set<vector<int>> &s, vector<int> &A){

    if(idx == A.size()){
        s.insert(A);
        return;
    }
    for(int i = idx; i < A.size(); i++){
        swap(A[i],A[idx]);
        solve(idx+1,s,A);
        swap(A[i],A[idx]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    
    set<vector<int>> s;
    solve(0,s,A);
    vector<vector<int>> res;
    
    for(auto x: s){
        res.push_back(x);
    }
    return res;
}
