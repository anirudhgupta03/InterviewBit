/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, vector<int> &inorder){
    
    if(root == NULL){
        return;
    }
    solve(root -> left,inorder);
    inorder.push_back(root->val);
    solve(root -> right,inorder);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
    vector<int> inorder;
        
    solve(A,inorder);
        
    int i,val1,val2;
    
    for(i = 0; i < inorder.size(); i++){
        if(inorder[i]> inorder[i+1]){
            val1 = inorder[i];
            val2 = inorder[i+1];
            break;
        }
    }
    for(int j = i + 1; j < inorder.size() - 1; j++){
        if(inorder[j] > inorder[j+1]){
            val2 = inorder[j+1];
            break;
        }
    }
    vector<int> res = {val2,val1};
    return res;
}
