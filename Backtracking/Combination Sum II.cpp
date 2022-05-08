//Method - 1
void solve(int ind, vector<int> &A, int B, vector<int> &v, set<vector<int>> &res){
    
    if(B == 0){
        res.insert(v);
        return;
    }
    if(ind == A.size()){
        return;
    }
    
    if(A[ind] <= B){
        v.push_back(A[ind]);
        solve(ind+1,A,B-A[ind],v,res);
        v.pop_back();
        solve(ind+1,A,B,v,res);
    }
//     else{
//         solve(ind+1,A,B,v,res);         Not required as A is sorted
//     }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    set<vector<int>> res;
    vector<int> v;
    
    solve(0,A,B,v,res);
    
    vector<vector<int>> ans;
    
    set<vector<int>> :: iterator it;
    
    for(it = res.begin(); it!=res.end(); it++){
        ans.push_back(*it);
    }
    
    return ans;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=G1fRTGRxXU8&t=1159s
void solve(int ind, int B, vector<int> &A, vector<int> &res, vector<vector<int>> &ans){
    if(B == 0){
        ans.push_back(res);
        return;
    }
    for(int i = ind; i < A.size(); i++){
        if(i > ind && A[i] == A[i - 1]) continue;
        if(A[i] > B) break;
        res.push_back(A[i]);
        solve(i + 1, B - A[i], A, res, ans);
        res.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<int> res;
    vector<vector<int>> ans;
    solve(0, B, A, res, ans);
    return ans;
}
