//Method - 1
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

//Method - 2
//Using Inorder Traversal
//Time Complexity : O(N)
//Space Complexity: O(N)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, vector<int> &ans){
    
    if(root == NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    vector<int> ans;
    solve(A,ans);
    return ans[B-1];
}

//Method - 3
//TC - O(N)
//SC - O(1)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, int &B, int &ans){
    
    if(root == NULL){
        return;
    }
    
    solve(root->left,B,ans);
    B--;
    
    if(B == 0){
        ans = root->val;
        return;
    }

    solve(root->right,B,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    
    int ans;
    
    solve(A,B,ans);
    
    return ans;
}
