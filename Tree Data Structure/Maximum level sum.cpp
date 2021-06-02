/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    
    int max_sum = INT_MIN;
    
    queue<TreeNode*> q;
    
    q.push(A);
    
    while(!q.empty()){
        
        int s = q.size();
        int sum = 0;
        while(s){
            TreeNode* curr = q.front();
            q.pop();
            sum += curr ->val;
            if(curr -> left) q.push({curr->left});
            if(curr -> right) q.push({curr -> right});
            s--;
        }
        max_sum = max(max_sum,sum);
    }
    return max_sum;
}
