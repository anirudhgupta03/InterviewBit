//Ref: https://www.interviewbit.com/problems/maximum-area-of-triangle/discussion/p/c-solution-its-all-about-writing-clean-code-in-this-question/75069/1958
int helper(vector<string> &A, int col, int a, int b){
    int n = A.size(), m = A[0].size();
    int base = abs(a-b)+1;
    int ans = 0;
    int ht = (m-1)-col+1;

    for(int j = m - 1; j > col; j--){
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(A[i][j] != A[a][col] && A[i][j] != A[b][col])
            {
                ans = (base*ht + 1)/2;
                flag = 1;
                break;
            }
        }
        ht--;
        if(flag == 1) break;
    }
    ht = col+1;
    for(int j = 0; j < col; j++){
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(A[i][j] != A[a][col] && A[i][j] != A[b][col]){
                ans = max(ans, (base*ht + 1)/2);
                flag = 1;
                break;
            }
        }
        ht--;
        if(flag==1) break;
    }
    return ans;
}

int Solution::solve(vector<string> &A) {
    
    int n = A.size(), m = A[0].size(), ans = 0;

    for(int j = 0; j < m; j++) {
        vector<int> first(3,-1);
        vector<int> last(3,-1);
        
        for(int i = 0; i < n; i++){
            if(A[i][j] == 'r' && first[0] == -1)
                first[0] = i;
            if(A[i][j] == 'g' && first[1] == -1)
                first[1] = i;
            if(A[i][j] == 'b' && first[2] == -1)
                first[2] = i;
        }

        for(int i = n - 1; i >= 0; i--){
            if(A[i][j] == 'r' && last[0] == -1)
                last[0] = i;
            if(A[i][j] == 'g' && last[1] == -1)
                last[1] = i;
            if(A[i][j] == 'b' && last[2] == -1)
                last[2] = i;
        }

        vector<int> v1 = {0,0,1,1,2,2};
        vector<int> v2 = {1,2,0,2,0,1};
        
        for(int i = 0; i < 6; i++){
            if(first[v1[i]] != -1 && last[v2[i]] != -1){
                ans = max(ans, helper(A, j, first[v1[i]], last[v2[i]]));
            }
        }
    }
    return ans;
}
