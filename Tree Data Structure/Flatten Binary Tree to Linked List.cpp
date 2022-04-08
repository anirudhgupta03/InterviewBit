//Method - 1
//Ref: https://www.youtube.com/watch?v=SrTydnU2aj8
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(TreeNode* A){
    
    if(A == NULL){
        return NULL;
    }
    if(A -> left == NULL && A -> right == NULL){
        return A;
    }
    
    TreeNode* ltail = solve(A->left);
    TreeNode* rtail = solve(A->right);
    
    if(ltail != NULL && rtail != NULL){
        ltail -> right = A -> right;
        A -> right = A -> left;
        A -> left = NULL;
    }
    else if(ltail != NULL){
        A -> right = A -> left;
        A -> left = NULL;
        return ltail;
    }
    return rtail;
}
TreeNode* Solution::flatten(TreeNode* A) {
    
    solve(A);
    return A;
}

//Method - 2
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output root pointer of tree.
 */
treenode* solve(treenode* A){
    if(A == NULL){
        return NULL;
    }
    treenode* l = solve(A -> left);
    treenode* r = solve(A -> right);

    if(l && r){
        treenode* temp1 = A -> left;
        treenode* temp2 = A -> right;
        A -> right = temp1;
        l -> right = temp2;
        A -> left = NULL;
        return r;
    }
    if(l){
        treenode* temp = A -> left; 
        A -> left = NULL;
        A -> right = temp;
        return l;
    }
    if(r){
        return r;
    }
    return A;
}
treenode* flatten(treenode* A) {
    solve(A);
    return A;    
}
