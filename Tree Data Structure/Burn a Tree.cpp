//Method - 1
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

//Method - 2
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

//Method - 3
//BFS + DFS
//Ref: https://www.youtube.com/watch?v=XLdpy0_6MR4
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void rec(TreeNode* parent, TreeNode* A, int B, TreeNode* &start, unordered_map<TreeNode*, TreeNode*> &par){

    if(A == NULL){
        return;
    }
    if(A -> val == B){
        start = A;
    }
    par[A] = parent;
    rec(A, A -> left, B, start, par);
    rec(A, A -> right, B, start, par);
}
int Solution::solve(TreeNode* A, int B) {
    TreeNode* start;
    unordered_map<TreeNode*,TreeNode*> par;
    rec(NULL,A,B,start, par);

    queue<TreeNode*> q;
    q.push(start);

    int steps = 0;
    unordered_set<TreeNode*> vis;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();

            if(vis.find(curr) != vis.end()) continue;
            vis.insert(curr);

            if(par[curr]){
                if(vis.find(par[curr]) == vis.end()){
                    q.push(par[curr]);
                }
            }
            if(curr -> left){
                if(vis.find(curr -> left) == vis.end()){
                    q.push(curr -> left);
                }
            }
            if(curr -> right){
                if(vis.find(curr -> right) == vis.end()){
                    q.push(curr -> right);
                }
            }
        }
        steps++;
    }
    return steps - 1;
}

//Method - 4
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &par, TreeNode* &start, int B){
    if(curr == NULL){
        return;
    }
    if(curr -> val == B){
        start = curr;
    }
    par[curr] = parent;
    dfs(curr -> left, curr, par, start, B);
    dfs(curr -> right, curr, par, start, B);
}
int Solution::solve(TreeNode* A, int B) {
    
    unordered_map<TreeNode*, TreeNode*> par;
    TreeNode* start;
    dfs(A, NULL, par, start, B);
    
    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({start, NULL});
    
    int minTime = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front().first, *parent = q.front().second;
            q.pop();
            
            if(curr -> left && curr -> left != parent){
                q.push({curr -> left, curr});
            }
            if(curr -> right && curr -> right != parent){
                q.push({curr -> right, curr});
            }
            if(par[curr] && par[curr] != parent){
                q.push({par[curr], curr});
            }
        }
        minTime++;
    }
    return minTime - 1;
}
