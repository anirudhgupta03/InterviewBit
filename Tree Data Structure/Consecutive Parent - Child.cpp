/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::consecutiveNodes(TreeNode* A) {

    if(A == NULL){
        return 0;
    }
    int count = 0;
    queue<TreeNode*> q;
    q.push(A);

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();

            if(curr -> left){
                if(abs(curr -> left -> val - curr -> val) == 1) count++;
                q.push(curr -> left);
            }
            if(curr -> right){
                if(abs(curr -> right -> val - curr -> val) == 1) count++;
                q.push(curr -> right);
            }
        }
    }
    return count;
}
