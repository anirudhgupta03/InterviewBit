/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* x;
void dfs(TreeNode* root, TreeNode* parent, int leaf, unordered_map<TreeNode*,TreeNode*> &par){
    if(root == NULL){
        return;
    }
    if(root -> val == leaf){
        x = root;
    }
    par[root] = parent;
    dfs(root->left,root,leaf,par);
    dfs(root->right,root,leaf,par);
}
int Solution::solve(TreeNode* A, int B) {
    
    unordered_map<TreeNode*,TreeNode*> par;
    
    dfs(A,NULL,B,par);
    
    unordered_map<TreeNode*,int> visited;
    
    visited[x] = 1;
    
    queue<pair<TreeNode*,int>> q;
    q.push({x,0});
    
    int ans = 1;
    
    while(!q.empty()){
        
        TreeNode* root = q.front().first;
        int level = q.front().second;
        q.pop();
        ans = max(ans,level);
        
        if(root->left != NULL && visited[root->left] == 0){
            visited[root->left] = 1;
            q.push({root->left,level+1});
        }
        if(root->right != NULL && visited[root->right] == 0){
            visited[root->right] = 1;
            q.push({root->right,level+1});
        }
        if(par[root] != NULL && visited[par[root]] == 0){
            visited[par[root]] = 1;
            q.push({par[root],level+1});
        }
    }
    return ans;
}
