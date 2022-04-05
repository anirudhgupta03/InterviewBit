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

//Alter
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* find(TreeNode* A, int B, TreeNode* &successor){

    while(A != NULL){

        if(A -> val < B){
            A = A -> right;
        }
        else if(A -> val > B){
            successor = A;
            A = A -> left;
        }
        else{
            return A;
        }
    }
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    
    TreeNode* successor = NULL;
    TreeNode* node = find(A,B,successor);

    if(node == NULL){
        return node;
    }

    if(node -> right){
        TreeNode* temp = node -> right;
        while(temp -> left){
            temp = temp -> left;
        }
        return temp;
    }
    else{
        return successor;
    }
}

//Simple & Straight
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {

   TreeNode* successor = NULL;
   while(A -> val != B){
       if(A -> val > B){
         successor = A;
         A = A -> left;
       }
       else if(A -> val < B){
         A = A -> right;
       }
   }
 
   if(A -> right){
       successor = A -> right;
       while(successor -> left){
           successor = successor -> left;
       }
   }
   return successor;
}
