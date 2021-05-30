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
void solve(TreeNode* root, vector<vector<int>> &res, vector<int> &temp, int B){
    
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        
        temp.push_back(root->val);
        B -= root->val;
        if(B == 0){
            res.push_back(temp);
        }
        temp.pop_back();
        return;
    }
    B -= root->val;
    temp.push_back(root->val);
    solve(root->left,res,temp,B);
    solve(root->right,res,temp,B);
    temp.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int>> res;
    vector<int> temp;
    
    solve(A,res,temp,B);
    
    return res;
}
