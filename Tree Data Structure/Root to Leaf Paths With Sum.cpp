/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, int B, vector<int> &res, vector<vector<int>> &ans){
    if(A == NULL){
        return;
    }
    if(A -> left == NULL && A -> right == NULL){
        if(B == A -> val){
            res.push_back(A -> val);
            ans.push_back(res);
            res.pop_back();
        }
        return;
    }
    res.push_back(A -> val);
    solve(A -> left, B - A -> val, res, ans);
    solve(A -> right, B - A -> val, res, ans);
    res.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> res;
    vector<vector<int>> ans;
    solve(A, B, res, ans);
    return ans;
}
