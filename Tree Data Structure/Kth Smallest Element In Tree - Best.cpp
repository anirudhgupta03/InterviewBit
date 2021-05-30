//TC - O(N)
//SC - O(1)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, int &B, int &ans){
    
    if(root == NULL){
        return;
    }
    
    solve(root->left,B,ans);
    B--;
    
    if(B == 0){
        ans = root->val;
        return;
    }

    solve(root->right,B,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    int ans;
    
    solve(A,B,ans);
    
    return ans;
}
