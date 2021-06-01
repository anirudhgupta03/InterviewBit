/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildBST(const vector<int> &A, int l, int r){
    
    if(l > r){
        return NULL;
    }
    
    int ind = (l+r)/2;
    TreeNode* root = new TreeNode(A[ind]);
    root->left = buildBST(A,l,ind-1);
    root->right = buildBST(A,ind+1,r);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(A.size() == 0){
        return NULL;
    }
    return buildBST(A,0,A.size() - 1);
}
