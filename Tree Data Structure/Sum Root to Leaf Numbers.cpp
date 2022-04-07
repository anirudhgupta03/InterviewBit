/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, long long &ans, long long temp){
    
    if(A == NULL){
        return;
    }
    if(A -> left == NULL && A -> right == NULL){
        temp = (10*temp + A->val)%1003;
        ans = (ans%1003 + temp%1003)%1003;
        return;
    }
    
    temp = (10*temp + A->val)%1003;
    
    solve(A->left,ans,temp);
    
    solve(A->right,ans,temp);
}
int Solution::sumNumbers(TreeNode* A) {
    
    long long ans = 0;
    
    solve(A,ans,0);
    
    return ans%1003;
}

//Alter
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int mod = 1e3 + 3;
int sum;
void solve(int num, TreeNode* A){
    if(A == NULL){
        return;
    }
    if(A -> left == NULL && A -> right == NULL){
        sum = (sum + 10*num + A -> val)%mod;
        return;
    }
    solve((10*num + A -> val)%mod, A -> left);
    solve((10*num + A -> val)%mod, A -> right);
}
int Solution::sumNumbers(TreeNode* A) {
    sum = 0;
    solve(0, A);
    return sum%mod;
}
