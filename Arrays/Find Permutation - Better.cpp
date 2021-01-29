vector<int> Solution::findPerm(const string A, int B) {
    
    int a = 1, b= B;
    
    vector<int> ans;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == 'D'){
            ans.push_back(b);
            b--;
        }
        else{
            ans.push_back(a);
            a++;
        }
        
    }
    ans.push_back(a);
    return ans;
}
