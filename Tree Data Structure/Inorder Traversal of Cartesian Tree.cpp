//Ref: https://www.youtube.com/watch?v=wv4XfOcIQWg
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildtree(vector<int> &A, int l, int r){
    
    if(l > r){
        return NULL;
    }
    
    int ind = -1, maxi = INT_MIN;
    
    for(int i = l; i <= r; i++){
        
        if(A[i] > maxi){
            maxi = A[i];
            ind = i;
        }
    }
    TreeNode* root = new TreeNode(A[ind]);
    root->left = buildtree(A,l,ind-1);
    root->right = buildtree(A,ind+1,r);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    return buildtree(A,0,A.size() - 1);
}
