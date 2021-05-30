/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPath(TreeNode* root, vector<int> &path, int B){
    
    if(root == NULL){
        return false;
    }
    
    if(root -> val == B){
        path.push_back(B);
        return true;
    }
    
    if(findPath(root->left,path,B) || findPath(root->right,path,B)){
        path.push_back(root->val);
        return true;
    }
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> path;
    
    findPath(A, path,B);
    
    reverse(path.begin(),path.end());
    
    return path;
}
