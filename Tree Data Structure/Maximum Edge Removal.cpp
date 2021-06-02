int helper(int node, vector<int> al[], int A, vector<int> &subSize){
    
    for(int i = 0; i < al[node].size(); i++){
        subSize[node] += helper(al[node][i],al,A,subSize);
    }
    return subSize[node];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A+1];
    
    for(int i = 0; i < B.size(); i++){
        int u = B[i][0], v = B[i][1];
        al[u].push_back(v);
    }
    
    vector<int> subSize(A+1,1);
    
    helper(1,al,A,subSize);
    
    int count = 0;
    
    for(int i = 2; i <= A; i++){
        if(subSize[i] % 2 == 0){
            count++;
        }
    }
    return count;
}
