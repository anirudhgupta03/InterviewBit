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
    int j;
    for(int i = l; i <= r; i++){
        if(B[i] == A[ind]){
            j = i;
            break;
        }
    }
    TreeNode* root = new TreeNode(A[ind]);
    ind++;
    root->left = solve(A,B,l,j-1,ind);
    root->right = solve(A,B,j+1,r,ind);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {   
    int ind = 0;
    return solve(A,B,0,B.size() - 1,ind);
}
