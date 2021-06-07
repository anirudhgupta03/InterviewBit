//Brute Force Approach
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
int Solution::maximumGap(const vector<int> &A) {
    
    if(A.size() < 2){
        return 0;
    }
    vector<int> B = A;
    
    sort(B.begin(),B.end());
    
    int diff = INT_MIN;
    
    for(int i = 1; i < B.size(); i++){
        diff = max(diff,B[i]-B[i-1]);
    }
    
    return diff;
}
//Optimal Approach
//Ref: https://www.youtube.com/watch?v=21XhR6r5jU8
//Pigeon Hole Principle
//Time Complexity - O(N)
//Space Complexity - O(N)
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

int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    
    if(n < 2){
        return 0;
    }
    
    int mine = *min_element(A.begin(),A.end());
    int maxe = *max_element(A.begin(),A.end());
    
    int bucketSize = (int)(ceil((double)(maxe-mine)/(n-1)));
    
    vector<int> minOfBucket(n-1,INT_MAX);
    vector<int> maxOfBucket(n-1,INT_MIN);
    
    for(int i = 0; i < n; i++){
        
        if(A[i] == mine || A[i] == maxe){
            continue;
        }
        int bucketIndexForCurrentEl = (A[i]-mine)/bucketSize;
        
        minOfBucket[bucketIndexForCurrentEl] = min(minOfBucket[bucketIndexForCurrentEl],A[i]);
        maxOfBucket[bucketIndexForCurrentEl] = max(maxOfBucket[bucketIndexForCurrentEl],A[i]);
    }
    
    int max_gap = INT_MIN;
    int prev = mine;
    
    for(int i = 0; i < n - 1; i++){
        
        if(minOfBucket[i] == INT_MAX){              //Empty buckets
            continue;
        }
        max_gap = max(max_gap,minOfBucket[i]-prev);
        prev = maxOfBucket[i];
    }
    
    max_gap = max(max_gap,maxe - prev);
    return max_gap;
}
