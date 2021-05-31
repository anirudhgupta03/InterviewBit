/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* root){
    
    if(root == NULL){
        return 0;
    }
    
    int l = height(root->left);
    int r = height(root->right);
    
    return 1 + max(l,r);
}
int Solution::isBalanced(TreeNode* A) {
    
    if(A == NULL){
        return true;
    }
    
    if(isBalanced(A->left) == NULL){
        return false;
    }
    if(isBalanced(A->right) == NULL){
        return false;
    }
    
    int lh = height(A->left);
    int rh = height(A->right);
    
    if(abs(lh-rh) <= 1){
        return true;
    }
    return false;
}
