//Ref: https://www.youtube.com/watch?v=SrTydnU2aj8
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
    if(A -> left == NULL && A -> right == NULL){
        return A;
    }
    
    TreeNode* ltail = solve(A->left);
    TreeNode* rtail = solve(A->right);
    
    if(ltail != NULL && rtail != NULL){
        ltail -> right = A -> right;
        A -> right = A -> left;
        A -> left = NULL;
    }
    else if(ltail != NULL){
        A -> right = A -> left;
        A -> left = NULL;
        return ltail;
    }
    return rtail;
}
TreeNode* Solution::flatten(TreeNode* A) {
    
    solve(A);
    return A;
}
