//Using Max Heap + Preorder Traversal
//Time Complexity: O(NlogK)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, int B, priority_queue<int,vector<int>> &pq){
    
    if(root == NULL){
        return;
    }
    
    pq.push(root->val);
    
    if(pq.size() > B){
        pq.pop();
    }
    
    solve(root -> left,B,pq);
    solve(root -> right,B,pq);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    priority_queue<int> pq;
    
    solve(A,B,pq);
    
    return pq.top();
}
