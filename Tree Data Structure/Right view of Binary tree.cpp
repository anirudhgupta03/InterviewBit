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
    
    queue<pair<TreeNode*,int>> q;
    
    map<int,int> mymap;
    
    q.push({A,0});
    
    while(!q.empty()){
        
        TreeNode* curr = q.front().first;
        int d = q.front().second;
        
        q.pop();
        mymap[d] = curr->val;
        
        if(curr -> left != NULL){
            q.push({curr->left,d+1});
        }
        if(curr -> right != NULL){
            q.push({curr->right,d+1});
        }
    }
    
    vector<int> res;
    map<int,int> :: iterator it;
    
    for(it = mymap.begin(); it != mymap.end(); it++){
        res.push_back(it->second);
    }
    return res;
}
