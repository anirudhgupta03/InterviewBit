/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, vector<int> &temp){
    
    if(root == NULL){
        return;
    }
    
    inorder(root->left,temp);
    temp.push_back(root->val);
    inorder(root->right,temp);
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    vector<int> temp1,temp2;
    
    inorder(A,temp1);
    inorder(B,temp2);
    
    if(temp1 == temp2){
        return 1;
    }
    return 0;
}
