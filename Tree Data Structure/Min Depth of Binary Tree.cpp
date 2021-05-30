/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, int &ans, int count){
    
    if(A == NULL){
        return;
    }
    if(A -> left == NULL && A->right == NULL){
        count++;
        ans = min(ans,count);
        return;
    }
    
    count++;
    solve(A->left,ans,count);
    solve(A->right,ans,count);
}
int Solution::minDepth(TreeNode* A) {
    
    int ans = INT_MAX;
    
    int count = 0;
    
    solve(A,ans,count);
    
    return ans;
}
