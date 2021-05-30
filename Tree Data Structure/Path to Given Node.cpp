//Using Backtracking
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPath(TreeNode* root, vector<int> &path, vector<int> &temp, int B){
    
    if(root == NULL){
        return;
    }
    
    if(root -> val == B){
        temp.push_back(B);
        path = temp;
        return;
    }
    
    temp.push_back(root->val);
    findPath(root->left,path,temp,B);
    findPath(root->right,path,temp,B);
    temp.pop_back();
}
vector<int> Solution::solve(TreeNode* A, int B) {
    
    vector<int> path,temp;
    findPath(A, path,temp,B);
    return path;
}
