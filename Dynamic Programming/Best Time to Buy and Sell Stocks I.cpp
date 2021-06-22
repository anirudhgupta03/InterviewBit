//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::maxProfit(const vector<int> &A) {
    
    int n = A.size();
    
    if(n <= 1){
        return 0;
    }
    
    int left[n], right[n];
    
    left[0] = A[0];
    
    for(int i = 1; i < n; i++){
        left[i] = min(left[i-1],A[i]);
    }
    
    right[n-1] = A[n-1];
    for(int i = n - 2; i >= 0; i--){
        right[i] = max(right[i+1],A[i]);
    }
    
    int maxProfit = 0;
    
    for(int i = 0; i <= n - 2; i++){
        maxProfit = max(maxProfit,right[i]-left[i]);
    }
    
    return maxProfit;
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::maxProfit(const vector<int> &A) {
    
    int n = A.size();
    
    if(n <= 1){
        return 0;
    }
    
    int maxProfit = 0;
    
    int minEle = A[0];
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i] > minEle){
            maxProfit = max(maxProfit,A[i] - minEle);
        }
        else if(A[i] < minEle){
            minEle = A[i];
        }
    }
    return maxProfit;
}
