void solve(int ind, vector<int> &A, int B, set<vector<int>> &res, vector<int> &ans){
    
    if(ind == A.size()){
        return;
    }
    if(B == 0){
        res.insert(ans);
        return;
    }
    
    if(A[ind] <= B){
        ans.push_back(A[ind]);
        solve(ind,A,B - A[ind],res,ans);
        ans.pop_back();
        solve(ind+1,A,B,res,ans);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    set<vector<int>> res;
    vector<int> ans;
    
    solve(0,A,B,res,ans);
    
    vector<vector<int>> sol;
    
    set<vector<int>> :: iterator it;
    for(it = res.begin(); it != res.end(); it++){
        sol.push_back(*it);
    }
    return sol;
}
