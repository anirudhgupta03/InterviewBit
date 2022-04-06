/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::verticalSum(TreeNode* A) {

    vector<int> res;
    if(A == NULL){
        return res;
    }
  
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({A,0});
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level] += curr -> val;
            if(curr -> left) q.push({curr -> left, level - 1});
            if(curr -> right) q.push({curr -> right, level + 1});
        }
    }
    for(auto x: mp){
        res.push_back(x.second);
    }
    return res;
}
