int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    
    if(n<2){
        return 0;
    }
    
    int maxe = A[0], mine = A[0];
    
    for(auto x: A){
        maxe = max(maxe,x);
        mine = min(mine,x);
    }
    
    int interval = (int)(ceil((double)(maxe-mine)/(n-1)));
    
    vector<int> bucketmin(n-1,INT_MAX);
    vector<int> bucketmax(n-1,INT_MIN);
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == mine || A[i] == maxe){
            continue;
        }
        bucketmin[(A[i]-mine)/interval] = min(bucketmin[(A[i]-mine)/interval],A[i]);
        bucketmax[(A[i]-mine)/interval] = max(bucketmax[(A[i]-mine)/interval],A[i]);
    }
    int a = mine, ans = 0;
    for(int i = 0; i < n-1; i++){
        if(bucketmin[i] == INT_MAX){
            continue;
        }
        ans =  max(ans,bucketmin[i]-a);
        a= bucketmax[i];
    }
    ans = max(ans,maxe-a);
    return ans;
}
