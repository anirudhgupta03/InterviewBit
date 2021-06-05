//Ref: https://www.youtube.com/watch?v=Osz-Vwer6rw
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* root, int &res){
    
    if(root == NULL){
        return 0;
    }
    
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    
    int temp = max(max(l,r) + root->val, root -> val);
    int ans = max(temp, l+r+root->val);
    res = max(res,ans);
    
    return temp;
}
int Solution::maxPathSum(TreeNode* A) {
    
    int res = INT_MIN;
    solve(A,res);
    return res;
}
