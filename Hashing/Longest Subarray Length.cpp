int Solution::solve(vector<int> &arr) {
    
    int n = arr.size();
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;
    
    // traverse the given array 
    for (int i = 0; i < n; i++) { 
    
        // consider '0' as '-1' 
        sum += arr[i] == 0 ? -1 : 1; 
    
        // when subarray starts form index '0' 
        if (sum == 1) 
            maxLen = i + 1; 
    
        // make an entry for 'sum' if it is 
        // not present in 'um' 
        else if (um.find(sum) == um.end()) 
            um[sum] = i; 
    
        // check if 'sum-1' is present in 'um' 
        // or not 
        if (um.find(sum - 1) != um.end()) {
    
            // update maxLength 
            if (maxLen < (i - um[sum - 1])) 
                maxLen = i - um[sum - 1]; 
        } 
    }
    return maxLen;
}
