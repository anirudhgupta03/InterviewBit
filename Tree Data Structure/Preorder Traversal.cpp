//Recursive
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Preorder Traversal - Root -> Left -> Right
void solve(TreeNode* A, vector<int> &v){
    
    if(A == NULL){
        return;
    }
    
    v.push_back(A -> val);
    solve(A -> left, v);
    solve(A -> right, v);
}
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> v;
    solve(A,v);
    
    return v;
}

//Iterative
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {

    vector<int> res;
    if(A == NULL){
        return res;
    }
    stack<TreeNode*> st;
    st.push(A);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        res.push_back(curr -> val);
        if(curr -> right) st.push(curr -> right);
        if(curr -> left) st.push(curr -> left);
    }
    return res;
}
