//Method - 1
//TC - O(N)
//SC - O(N)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, vector<int> &inorder){
    
    if(root == NULL){
        return;
    }
    solve(root -> left,inorder);
    inorder.push_back(root->val);
    solve(root -> right,inorder);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
    vector<int> inorder;
        
    solve(A,inorder);
        
    int i,val1,val2;
    
    for(i = 0; i < inorder.size(); i++){
        if(inorder[i]> inorder[i+1]){
            val1 = inorder[i];
            val2 = inorder[i+1];
            break;
        }
    }
    for(int j = i + 1; j < inorder.size() - 1; j++){
        if(inorder[j] > inorder[j+1]){
            val2 = inorder[j+1];
            break;
        }
    }
    vector<int> res = {val2,val1};
    return res;
}

//Method - 2
//TC - O(N)
//SC - O(1)
//Ref: https://www.youtube.com/watch?v=HsSSUSckMns
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &pre){
    
    if(root == NULL){
        return;
    }
    
    solve(root->left,first,second,pre);
    
    if(first == NULL && pre->val > root->val){
        first = pre;
    }
    if(first != NULL && pre->val > root->val){
        second = root;
    }
    pre = root;
    solve(root->right,first,second,pre);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
    
    solve(A,first,second,pre);
    
    vector<int> res = {second->val,first->val};
    
    return res;
}

//Method - 3
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, int &pre, int &flag, int &val1, int &val2){
    
    if(A == NULL){
        return;
    }
    solve(A -> left, pre, flag, val1, val2);
    if(A -> val < pre){
        if(flag == 0){
            val1 = pre;
            val2 = A -> val;
            flag = 1;
        }
        else{
            val2 = A -> val;
        }
    }
    pre = A -> val;
    solve(A -> right, pre, flag, val1, val2);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
    int val1, val2, flag = 0, pre = INT_MIN;
    solve(A, pre, flag, val1, val2);
    vector<int> res = {val1, val2};
    sort(res.begin(), res.end());
    return res;
}
