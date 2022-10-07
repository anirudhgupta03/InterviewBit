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

//Method - 3
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* A){
    if(A == NULL){
        return 0;
    }
    int lht = solve(A -> left);
    int rht = solve(A -> right);
    if(abs(lht - rht) > 1 || lht == -1 || rht == -1){
        return -1;
    }
    return 1 + max(lht, rht);
}
int Solution::isBalanced(TreeNode* A) {
    int res = solve(A);
    if(res == -1) return 0;
    return 1;
}
