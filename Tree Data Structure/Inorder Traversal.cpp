//Recurive
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
    
    if(A == NULL){
        return;
    }
    
    solve(A -> left, v);
    v.push_back(A -> val);
    solve(A -> right, v);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
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
vector<int> Solution::inorderTraversal(TreeNode* A) {

    stack<TreeNode*> st;
    
    while(A){
        st.push(A);
        A = A -> left;
    }

    vector<int> res;

    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        res.push_back(curr -> val);
        curr = curr -> right;
        while(curr){
            st.push(curr);
            curr = curr -> left;
        }
    }
    return res;
}
