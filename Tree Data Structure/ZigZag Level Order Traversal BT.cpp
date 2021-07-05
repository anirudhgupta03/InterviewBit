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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>> res;

    queue<TreeNode*> q;

    q.push(A);

    bool flag = 0;

    while(!q.empty()){
        vector<int> temp;
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            temp.push_back(curr -> val);
            q.pop();
            if(curr -> left != NULL) q.push(curr -> left);
            if(curr -> right != NULL) q.push(curr -> right);
        }
        if(flag){
            reverse(temp.begin(),temp.end());
            flag = 0;
        }
        else{
            flag = 1;
        }
        res.push_back(temp);
    }
    return res;
}
