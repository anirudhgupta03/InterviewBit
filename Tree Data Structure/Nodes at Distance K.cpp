/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void find(TreeNode* parent, TreeNode* A, int B, TreeNode* &target, unordered_map<TreeNode*, TreeNode*> &par){
    if(A == NULL){
        return;
    }
    if(A -> val == B){
        target = A;
    }
    par[A] = parent;
    find(A, A -> left, B, target, par);
    find(A, A -> right, B, target, par);
}
vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    TreeNode* target;
    unordered_map<TreeNode*, TreeNode*> par;
    find(NULL, A, B, target, par);

    vector<int> res;

    queue<TreeNode*> q;
    q.push(target);

    unordered_set<TreeNode*> vis;
    C++;
    while(!q.empty() && C--){
        vector<int> temp;
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();

            temp.push_back(curr -> val);

            if(vis.find(curr) != vis.end()) continue;
            vis.insert(curr);

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
            if(par[curr]){
                if(vis.find(par[curr]) == vis.end()){
                    q.push(par[curr]);
                }
            }
        }
        res = temp;
    }
    return res;
}
