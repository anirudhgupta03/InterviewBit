/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(vector<int> &A, vector<int> &B, int l, int r, int &ind){
    
    if(l > r){
        return NULL;
    }
    int i;
    for(i = l; i <= r; i++){
        
        if(A[i]== B[ind]){
            break;
        }
    }
    TreeNode* root = new TreeNode(B[ind]);
    ind--;
    root->right = solve(A,B,i+1,r,ind);
    root->left = solve(A,B,l,i-1,ind);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int ind = B.size()-1;
    return solve(A,B,0,A.size()-1,ind);
}
