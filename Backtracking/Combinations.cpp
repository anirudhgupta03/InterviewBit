//Method - 1
void solve(int ind, int B, vector<int> &num, vector<int> &p, vector<vector<int>> &v){
    
    if(p.size() == B){
        v.push_back(p);
        return;
    }
    
    p.push_back(num[ind]);
        
    solve(ind+1,B,num,p,v);
        
    p.pop_back();

    if(B - p.size() < num.size() - ind){
        solve(ind+1,B,num,p,v);
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<int> num;
    
    for(int i = 1; i <= A; i++){
        num.push_back(i);
    }
    
    vector<int> p;
    vector<vector<int>> v;
    
    if(B > A){
        return v;
    }
    solve(0,B,num,p,v);
    
    return v;
}

//Method - 2
void solve(vector<vector<int>> &vec,vector<int> &v,int B,vector<int> &p, int ind){
    
    if(B == 0){
        vec.push_back(p);
        return;
    }
    for(int i = ind; i < v.size(); i++){
            p.push_back(v[i]);
            solve(vec,v,B-1,p,i+1);
            p.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<int> v(A);
    
    for(int i = 0; i < A; i++){
        v[i] = i + 1;
    }
    
    vector<vector<int>> vec;
    
    vector<int> p;
    
    solve(vec,v,B,p,0);
    
    sort(vec.begin(),vec.end());
    
    return vec;
}

//Method - 3
void solve(int ind, vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int B){
    
    if(B == 0){
        res.push_back(temp);
        return;
    }
    if(ind == nums.size()){
        return;
    }
    for(int i = ind; i < nums.size(); i++){
        
        temp.push_back(nums[i]);
        solve(i+1,res,temp,nums,B-1);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<int> nums(A);
    for(int i = 0; i < A; i++){
        nums[i] = i + 1;
    }
    vector<vector<int>> res;
    vector<int> temp;
    solve(0,res,temp,nums,B);
    return res;
}
