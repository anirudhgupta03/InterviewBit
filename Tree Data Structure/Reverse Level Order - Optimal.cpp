/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> ans;
    
    queue<TreeNode*> q;
    
    q.push(A);
    
    while(!q.empty()){
        
        TreeNode* curr = q.front();
        q.pop();
        
        ans.push_back(curr->val);
        
        if(curr -> right != NULL){
            q.push(curr -> right);
        }
        if(curr -> left != NULL){
            q.push(curr -> left);
        }
        
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
