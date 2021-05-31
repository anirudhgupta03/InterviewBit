/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, unordered_map<int,vector<int>> &myumap){
    
    queue<pair<TreeNode*,int>> q;
    
    q.push({root,0});
    
    while(!q.empty()){
        
        TreeNode* curr = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if(curr == NULL)
        myumap[d].push_back(-1);
        else{
            myumap[d].push_back(curr->val);
        }
        
        if(curr != NULL){
            q.push({curr->left,d+1});
            q.push({curr->right,d+1});
        }
        
    }
}
int Solution::isSymmetric(TreeNode* A) {
    
    unordered_map<int,vector<int>> myumap;
    
    solve(A,myumap);
    
    for(auto u : myumap){
        
        vector<int> temp1 = u.second;
        
        vector<int> temp2 = temp1;
        
        reverse(temp2.begin(),temp2.end());
        
        if(temp1 != temp2){
            return 0;
        }
    }
    return 1;
}
