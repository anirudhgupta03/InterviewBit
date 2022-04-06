//Method - 1
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

//Method - 2
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
