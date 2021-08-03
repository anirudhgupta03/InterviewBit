//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(N)
int Solution::jump(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1){
        return 0;
    }
    int dp[n];
    
    memset(dp,0,sizeof(dp));
    
    int cov = 0;
    
    for(int i = 0; i < n - 1; i++){
        
        if(i == 0 || dp[i]){
            for(int j = cov + 1; j <= i + A[i]; j++){
                if(j < n){
                    dp[j] = dp[i] + 1;
                }
                else{
                    break;
                }
                cov = max(cov,i + A[i]);
            }
        }
        else{
            return -1;
        }
    }
    
    if(!dp[n-1]){
        return -1;
    }
    return dp[n-1];
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::jump(vector<int> &A) {

    int n = A.size();

    if(n == 1){
        return 0;
    }
    else if(A[0] == 0){
        return -1;
    }

    int maxR = A[0], steps = A[0], jumps = 0;

    for(int i = 1; i < n; i++){
        
        if(i == n - 1){
            return jumps + 1;
        }
        steps--;
        maxR = max(maxR, i + A[i]);

        if(steps == 0){

            if(maxR > i){
                steps = maxR - i;
                jumps++;
            }
            else{
                return -1;
            }
        }
    }
}
