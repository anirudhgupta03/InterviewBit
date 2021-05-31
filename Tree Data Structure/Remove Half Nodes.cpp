//Ref: https://www.youtube.com/watch?v=dKz9E5CYE4k&t=28s
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    
    if(A == NULL){
        return NULL;
    }
    
    if(A->left == NULL &&  A->right == NULL){
        return A;
    }
    
    if(A->left == NULL){
        return solve(A->right);
    }
    if(A->right == NULL){
        return solve(A->left);
    }
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
}
