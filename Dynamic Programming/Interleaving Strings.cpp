//Method - 1
int check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3,unordered_map<string,int> &mem){
        
    if(p3 == len3){
        return (p1 == len1 && p2 == len2) ? 1 : 0;
    }
        
    string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        
        if(mem.find(key)!=mem.end()){
            return mem[key];
        }
        
        if(p1 == len1){
            if(s2[p2] == s3[p3]){
                return mem[key] = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mem);
            }
            else{
                return mem[key] = 0;
            }
        }
        if(p2 == len2){
            if(s1[p1] == s3[p3]){
                return mem[key] = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mem);
            }
            else{
                return mem[key] = 0;
            }
        }
        
        bool one = 0, two = 0;
        
        if(s1[p1] == s3[p3]){
            one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mem);
        }
        if(s2[p2] == s3[p3]){
            two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mem);
        }
        return mem[key] = one || two;
}
int Solution::isInterleave(string A, string B, string C) {
    int len1 = A.length();
        int len2 = B.length();
        int len3 = C.length();
        
        if(len1 + len2 != len3){
            return 0;
        }
        unordered_map<string,int> mem;
        return check(A,B,C,len1,len2,len3,0,0,0,mem);
}

//Method - 2
//Top-Down
//TC - O(len1*len2)
//SC - O(151*151)
int len1, len2, len3;
string s1, s2, s3;
int dp[151][151];
int solve(int ind1, int ind2, int ind3){

    if(ind3 == len3){
        return dp[ind1][ind2] = 1;
    }

    if(dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }

    if(ind1 == len1){
        if(s2[ind2] == s3[ind3]){
            return dp[ind1][ind2] = solve(ind1, ind2 + 1, ind3 + 1);    
        }
        else{
            return dp[ind1][ind2] = 0;
        }
    }
    if(ind2 == len2){
        if(s1[ind1] == s3[ind3]){
            return dp[ind1][ind2] = solve(ind1 + 1, ind2, ind3 + 1);
        }
        else{
            return dp[ind1][ind2] = 0;
        }
    }
    bool flag = false;
    if(s1[ind1] == s3[ind3]){
        flag |= solve(ind1 + 1, ind2, ind3 + 1);
    }
    if(s2[ind2] == s3[ind3]){
        flag |= solve(ind1, ind2 + 1, ind3 + 1);
    }
    return dp[ind1][ind2] = flag;
}
int Solution::isInterleave(string A, string B, string C) {
    len1 = A.size();
    len2 = B.size();
    len3 = C.size();
    s1 = A;
    s2 = B;
    s3 = C;
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0);
}

//Method - 3
//Top-Down
int solve(int ptr1, int ptr2, int ptr3, string &A, string &B, string &C, vector<vector<int>> &dp){
    
    if(ptr3 == C.size()){
        return 1;
    }
    
    if(dp[ptr1][ptr2] != -1){
        return dp[ptr1][ptr2];
    }
    if(ptr1 < A.size() && A[ptr1] == C[ptr3]){
        if(solve(ptr1 + 1, ptr2, ptr3 + 1, A, B, C, dp)){
            return 1;
        }
    }
    if(ptr2 < B.size() && B[ptr2] == C[ptr3]){
        if(solve(ptr1, ptr2 + 1, ptr3 + 1, A, B, C, dp)){
            return 1;
        }
    }
    return 0;
}
int Solution::isInterleave(string A, string B, string C) {
    
    int len1 = A.size(), len2 = B.size(), len3 = C.size();
    
    if(len1 + len2 != len3){
        return 0;
    }
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
    return solve(0, 0, 0, A, B, C, dp);
}
