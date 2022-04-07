//Method - 1
//TC - O(N*N)
//SC - O(N)
//BST from inorder and preorder
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildTree(vector<int> &A, vector<int> &B, int &ind, int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    TreeNode* root = new TreeNode(A[ind]);
    int i;
    for(i = lo; i <= hi; i++){
        if(B[i] == A[ind]){
            break;
        }
    }
    ind++;
    root -> left = buildTree(A, B, ind, lo, i - 1);
    root -> right = buildTree(A, B, ind, i + 1, hi);
    return root;
}
TreeNode* Solution::constructBST(vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end());
    int ind = 0;
    return buildTree(A, B, ind, 0, A.size() - 1);
}

//Method - 2
//TC - O(N)
//SC - O(1)
//Ref: https://www.youtube.com/watch?v=Bexswo4pqZQ
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildTree(int &ind, vector<int> &A, int lr, int rr){

    if(ind >= A.size() || A[ind] < lr || A[ind] > rr){
        return NULL;
    }
    TreeNode* node = new TreeNode(A[ind]);
    ind++;
    node -> left = buildTree(ind, A, lr,node -> val);
    node -> right = buildTree(ind, A, node -> val, rr);
    return node;
}
TreeNode* Solution::constructBST(vector<int> &A) {
    int n = A.size();
    int lr = INT_MIN, rr = INT_MAX, ind = 0;
    return buildTree(ind, A, lr, rr);
}
