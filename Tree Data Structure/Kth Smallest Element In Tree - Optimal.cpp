//Using Inordere Traversal
//Time Complexity : O(N)
//Space Complexity: O(N)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, vector<int> &ans){
    
    if(root == NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    vector<int> ans;
    solve(A,ans);
    return ans[B-1];
}
