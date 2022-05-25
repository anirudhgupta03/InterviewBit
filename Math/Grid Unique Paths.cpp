//Method - 1
int paths(int x, int y, int a, int b){
    
    if(x == a && y == b){
        return 1;
    }
    else if(x == a + 1|| y == b + 1){
        return 0;
    }
    return paths(x,y+1,a,b)+paths(x+1,y,a,b);
}
 
int Solution::uniquePaths(int A, int B) {
    
    return paths(0,0,A-1,B-1);
}

//Method - 2
int paths(int x, int y, int a, int b, vector<vector<int>> &dp){
    
    if(x == a && y == b){
        return 1;
    }
    else if(x == a + 1|| y == b + 1){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    else{
        dp[x][y] = paths(x,y+1,a,b,dp)+paths(x+1,y,a,b,dp);
        return dp[x][y];
    }
}

int Solution::uniquePaths(int A, int B) {
    
    vector<vector<int>> dp;
    
    for(int i = 0; i < A; i++){
        vector<int> v;
        for(int j = 0; j < B; j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    
    return paths(0,0,A-1,B-1,dp);
    
}

//Method - 3
int Solution::uniquePaths(int A, int B) {
    
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
            long long ans = 1;
            for (int i = B; i < (A + B - 1); i++) {
                ans *= i;
                ans /= (i - B + 1);
            }
            return (int)ans;
}

//Method - 4
int Solution::uniquePaths(int A, int B) {
    A--;
    B--;
    int ans = 1;
    for(int i = 1; i <= min(A, B); i++){
        ans *= (A + B - i + 1);
        ans /= i;
    }
    return ans;
}
