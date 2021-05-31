/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* A, bool &flag){
    
    if(A == NULL){
        return 0;
    }
    
    int l = solve(A->left,flag);
    int r = solve(A->right,flag);
    
    if(abs(r-l) > 1){
        flag = false;
    }
    return max(l,r)+1;
}
int Solution::isBalanced(TreeNode* A) {
    
    bool flag = true;
    
    solve(A,flag);
    
    return flag;
}
