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
void solve(TreeNode* A, vector<int> &v){     
     if(A == NULL) return;
     solve(A->left,v);
     solve(A->right,v);
     v.push_back(A -> val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v;
    solve(A, v);
    return v;
}

//Iterative - 1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    st.push(A);
    vector<int> res;
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        res.push_back(curr -> val);
        if(curr -> left) st.push(curr -> left);
        if(curr -> right) st.push(curr -> right);
    }
    reverse(res.begin(), res.end());
    return res;
}

//Iterative - 2
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
    
    stack<TreeNode*> st;
    st.push(A);
    
    vector<int> res;
    
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        
        res.push_back(curr -> val);
        
        if(curr -> right) st.push(curr -> right);
        if(curr -> left) st.push(curr -> left);
    }
    return res;
}
