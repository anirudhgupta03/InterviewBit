/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* solve(TreeNode* A){
    
    if(A == NULL){
        return NULL;
    }
    
    TreeNode* l = solve(A->left);
    TreeNode* r = solve(A->right);
    
    A->left = r;
    A->right = l;
    
    return A;
}
TreeNode* Solution::invertTree(TreeNode* A) {
    
    return solve(A);
}
