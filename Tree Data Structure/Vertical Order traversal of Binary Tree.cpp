/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root,map<int,vector<int>> &mymap){
    
    queue<pair<TreeNode*,int>> q;
    
    q.push({root,0});
    
    while(!q.empty()){
        
        TreeNode* curr = q.front().first;
        int currd = q.front().second;
        
        q.pop();
        
        mymap[currd].push_back(curr->val);
        
        if(curr -> left != NULL){
            q.push({curr->left,currd-1});
        }
        if(curr->right != NULL){
            q.push({curr->right,currd+1});
        }
    }
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    map<int,vector<int>> mymap;
    vector<vector<int>> res;
    
    if(A == NULL){
        return res;
    }
    solve(A,mymap);
    
    for(auto x: mymap){
        res.push_back(x.second);
    }
    return res;
}
