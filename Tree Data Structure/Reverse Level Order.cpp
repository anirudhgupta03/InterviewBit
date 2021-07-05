//Method - 1
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
    
    map<int,vector<int>> mymap;
    
    queue<pair<TreeNode*,int>> q;
    
    q.push({A,0});
    
    while(!q.empty()){
        
        TreeNode* curr = q.front().first;
        int level = q.front().second;
        q.pop();
        
        mymap[level].push_back(curr->val);
        
        if(curr -> left != NULL){
            q.push({curr -> left,level+1});
        }
        if(curr -> right != NULL){
            q.push({curr -> right,level+1});
        }
        
    }
    
    vector<int> res;
    vector<vector<int>> temp;
    for(auto x: mymap){
        temp.push_back(x.second);
    }
    reverse(temp.begin(),temp.end());
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[i].size(); j++){
            res.push_back(temp[i][j]);
        }
    }
    return res;
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
