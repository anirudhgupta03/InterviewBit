/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* find(TreeNode* root, int data){
    while(root != NULL){
        if(root -> val == B){
            return root;
        }
        else if(root -> val < B){
            root = root -> right;
        }
        else{
            root = root -> left;
        }
    }
    return NULL;
}

TreeNode* findMin(TreeNode* root){
    if(root == NULL) return NULL;
    while(root -> left != NULL) root = root -> left;
    return root;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    
    TreeNode* current = find(A,B);
    
    if(current == NULL){
        return NULL;
    }
    
    if(current -> right != NULL){
        return findMin(current -> right);
    }
    else{
        TreeNode* successor = NULL, *ancestor = A;
        while(ancestor != current){
            if(current -> val < ancestor -> val){
                successor = ancestor;
                ancestor = ancestor -> left;
            }
            else{
                ancestor = ancestor -> right;
            }
        }
        return successor;
    }
}
