/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> st;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!st.empty()) st.pop();
    while(root){
        st.push(root);
        root = root -> left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!st.empty()){
        return true;
    }
    return false;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* curr = st.top();
    st.pop();
    int ans = curr -> val;
    curr = curr -> right;
    while(curr){
        st.push(curr);
        curr = curr -> left;
    }
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
