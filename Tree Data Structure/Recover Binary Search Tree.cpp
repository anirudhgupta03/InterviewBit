//Ref: https://www.youtube.com/watch?v=HsSSUSckMns
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &pre){
    
    if(root == NULL){
        return;
    }
    
    solve(root->left,first,second,pre);
    
    if(first == NULL && pre->val > root->val){
        first = pre;
    }
    if(first != NULL && pre->val > root->val){
        second = root;
    }
    pre = root;
    solve(root->right,first,second,pre);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
    
    solve(A,first,second,pre);
    
    vector<int> res = {second->val,first->val};
    
    return res;
}
