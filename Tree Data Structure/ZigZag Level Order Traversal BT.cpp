/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    
    map<int,vector<int>> mymap;
    
    queue<pair<int,TreeNode*>> q;
    
    q.push({0,A});
    
    while(!q.empty()){
        
        int currd = q.front().first;
        TreeNode* currnode = q.front().second;
        q.pop();
        
        mymap[currd].push_back(currnode->val);
        
        if(currnode -> left != NULL){
            q.push({currd+1,currnode->left});
        }
        
        if(currnode->right != NULL){
            q.push({currd+1,currnode->right});
        }
    }
    
    vector<vector<int>> res;
    
    map<int,vector<int>> :: iterator it;
    
    vector<int> temp;
    
    for(it = mymap.begin(); it != mymap.end(); it++){
        temp = it->second;
        
        if(it->first % 2 != 0){
            reverse(temp.begin(),temp.end());
        }
        res.push_back(temp);
    }
    return res;
}
