/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* root1, TreeNode* root2){
    
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    if(root1 -> val == root2 -> val){
        
        if(solve(root1 -> left,root2-> right) && solve(root1 -> right, root2->left)){
            return true;
        }
    }
    return false;
}
int Solution::isSymmetric(TreeNode* A) {
    
    return solve(A,A);
}
