/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    
    if(A != NULL && B == NULL){
        return A;
    }
    
    if(A == NULL &&  B != NULL){
        return B;
    }
    
    if(A != NULL && B != NULL){
        A -> val = A -> val + B -> val;
        A -> left = solve(A -> left,B -> left);
        A -> right = solve(A -> right,B -> right);
    }
    return A;
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
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(A && B){
        A -> val = A -> val + B -> val;
        A -> left = solve(A -> left, B -> left);
        A -> right = solve(A -> right, B -> right);
        return A;
    }
    if(A) return A;
    if(B) return B;
    return NULL;
}
