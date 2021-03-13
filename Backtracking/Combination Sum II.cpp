void solve(int ind, vector<int> &temp, set<vector<int>> &s, vector<int> &A, int B){
    
    if(ind == A.size()){
        if(B == 0){
            s.insert(temp);
        }
        return;
    }
    else if(B == 0){
        s.insert(temp);
        return;
    }
    
    if(A[ind] <= B){
        
        solve(ind+1,temp,s,A,B);
        
        temp.push_back(A[ind]);
        
        solve(ind+1,temp,s,A,B-A[ind]);
        
        temp.pop_back();
    }
    else{
        
        solve(ind+1,temp,s,A,B);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    set<vector<int>> s;
    
    vector<int> temp;
    
    vector<vector<int>> v;
    
    solve(0,temp,s,A,B);
    
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it!=s.end(); it++){
        v.push_back(*it);
    }
    sort(v.begin(),v.end());
    
    return v;
}
