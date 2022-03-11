//Find LIS for original array and reverse array
//Method - 1
//TC - O(n*n)
//SC - O(n)
int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    
    vector<int> fl(n,1);
    for(int i = 1; i < n; i++){
        
        for(int j = i - 1; j >= 0; j--){
            if(A[i] > A[j])
            fl[i] = max(fl[j]+1,fl[i]);
        }
    }
    
    vector<int> lf(n,1);
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            
            if(A[i] > A[j])
            lf[i] = max(lf[j] +1, lf[i]);
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans = max(lf[i] + fl[i] - 1,ans);
    }
    
    return ans;
}

//Method - 2
//TC - O(n*log(n))
//SC - O(n)
int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int len = A.size();
    if(len == 0){
        return 0;
    }
    vector<int> dp1(len,1), dp2(len,1);
    
    vector<int> temp;
    temp.push_back(A[0]);
    for(int i = 1; i < len; i++){
        if(A[i] > temp.back()){
            temp.push_back(A[i]);
        }
        else{
            int ind  = lower_bound(temp.begin(), temp.end(), A[i]) - temp.begin();
            if(ind != temp.size()){
                temp[ind] = A[i];
            }
        }
        dp1[i] = temp.size();
    }
    
    temp.clear();
    temp.push_back(A[len - 1]);

    for(int i = len - 2; i >= 0; i--){
        if(A[i] > temp.back()){
            temp.push_back(A[i]);
        }
        else{
            int ind  = lower_bound(temp.begin(), temp.end(), A[i]) - temp.begin();
            if(ind != temp.size()){
                temp[ind] = A[i];
            }
        }
        dp2[i] = temp.size();
    }
    int maxLen = 0;
    for(int i = 0; i < len; i++){
        maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
    }
    return maxLen;
}
