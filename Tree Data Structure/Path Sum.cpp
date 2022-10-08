//Method - 1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    
    if(A == NULL){
        return 0;
    }
    
    if(A -> left == NULL && A -> right == NULL){
        B -= A->val;
        if(B == 0){
            return 1;
        }
        return 0;
    }
    
    B -= A->val;
    
    if(hasPathSum(A->left,B) || hasPathSum(A->right,B)){
        return 1;
    }
    return 0;
}

//Method - 2
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A == NULL){
        return false;
    }
    if(A -> left == NULL && A -> right == NULL){
        if(B == A -> val){
            return true;
        }
        return false;
    }
    return hasPathSum(A -> left, B - A -> val) || hasPathSum(A -> right, B - A -> val);
}
