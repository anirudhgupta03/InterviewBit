/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, unordered_map<int,int> &umap){
    
    if(root == NULL){
        return;
    }
    
    umap[root->val]++;
    solve(root->left,umap);
    solve(root->right,umap);
}
int Solution::t2Sum(TreeNode* A, int B) {
    
    unordered_map<int,int> umap;
    
    solve(A,umap);
    
    unordered_map<int,int> :: iterator it;
    
    for(it = umap.begin(); it!= umap.end(); it++){
        
        if(umap.find(B - it->first) != umap.end() && umap.find(B - it->first) != it){
            return 1;
        }
    }
    return 0;
}
