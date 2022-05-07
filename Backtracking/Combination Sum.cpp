//Method - 1
set<vector<int>> s;

void solve(vector<int> &A,vector<int> &v, int B, int ind){
    
    if(ind == A.size()){
        if(B == 0){
            s.insert(v);
        }
        return;
    }
    else if(B == 0){
        s.insert(v);
        return;
    }
    
    if(A[ind] <= B){
        solve(A,v,B,ind+1);
        v.push_back(A[ind]);
        solve(A,v,B-A[ind],ind);
        v.pop_back();
    }
    else{
        solve(A,v,B,ind+1);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    vector<int> v;
    
    vector<vector<int>> vec;
    
    int ind = 0;
    
    solve(A,v,B,ind);
    
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it!=s.end(); it++){
        vec.push_back(*it);
    }
    s.clear();
    sort(vec.begin(),vec.end());
    return vec;
}

//Method - 2
set<vector<int>> s;

void solve(vector<int> &A,vector<int> v, int B, int ind){
    
    if(ind == A.size()){
        if(B == 0){
            s.insert(v);
        }
        return;
    }
    else if(B == 0){
        s.insert(v);
        return;
    }
    
    if(A[ind] <= B){
        solve(A,v,B,ind+1);
        v.push_back(A[ind]);
        solve(A,v,B-A[ind],ind);
    }
    else{
        solve(A,v,B,ind+1);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    vector<int> v;
    
    vector<vector<int>> vec;
    
    int ind = 0;
    
    solve(A,v,B,ind);
    
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it!=s.end(); it++){
        vec.push_back(*it);
    }
    s.clear();
    sort(vec.begin(),vec.end());
    return vec;
}

//Method - 3
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

//Method - 4
//Best
void solve(int ind, int B, vector<int> &C, vector<int> &temp, vector<vector<int>> &res){
    if(B == 0){
        res.push_back(temp);
        return;
    }
    if(ind == C.size()){
        return;
    }
    if(C[ind] <= B){
        temp.push_back(C[ind]);
        solve(ind, B - C[ind], C, temp, res);
        temp.pop_back();
        solve(ind + 1, B, C, temp, res);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<int> st;
    for(int x: A){
        st.insert(x);
    }
    vector<int> C;
    for(auto x: st){
        C.push_back(x);
    }
    vector<int> temp;
    vector<vector<int>> res;
    solve(0, B, C, temp, res);
    return res;
}
