/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, vector<int> &v){
    
    if(A == NULL){
        return;
    }
    
    solve(A -> left, v);
    v.push_back(A -> val);
    solve(A -> right, v);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> v;
    
    solve(A,v);
    
    return v;
}
