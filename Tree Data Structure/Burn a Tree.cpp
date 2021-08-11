//Using BFS + DFS
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

//Using BFS
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A, int B) {

    unordered_map<TreeNode*, TreeNode*> parent;

    queue<TreeNode*> q;
    parent[A] = NULL;
    q.push(A);

    TreeNode* start;

    while(!q.empty()){

        TreeNode* curr = q.front();
        if(curr -> val == B){
            start = curr;
        }
        q.pop();

        if(curr -> left){
            parent[curr -> left] = curr;
            q.push(curr -> left);
        }
        if(curr -> right){
            parent[curr -> right] = curr;
            q.push(curr -> right);
        }
    }

    q.push(start);
    unordered_map<TreeNode*, int> burn;
    burn[start] = 0;

    int burnTime = 0;

    while(!q.empty()){

        TreeNode* curr = q.front();
        burnTime = max(burnTime, burn[curr]);
        q.pop();

        if(curr -> left && burn.find(curr -> left) == burn.end()){
            q.push(curr -> left);
            burn[curr -> left] = burn[curr] + 1;
        }
        if(curr -> right && burn.find(curr -> right) == burn.end()){
            q.push(curr -> right);
            burn[curr -> right] = burn[curr] + 1; 
        }
        if(parent[curr] && burn.find(parent[curr]) == burn.end()){
            q.push(parent[curr]);
            burn[parent[curr]] = burn[curr] + 1;
        }
    }
    return burnTime;
}
