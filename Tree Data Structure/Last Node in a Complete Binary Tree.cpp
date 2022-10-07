//Method - 1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::lastNode(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    int ele;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();
            ele = curr -> val;
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
    }
    return ele;
}

//Method - 2
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans; 
int height(TreeNode* root){
    if(!root) return 0;
    return 1 + height(root->left);
}

void rec(TreeNode* root){
    if(!root) return;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if(h1 == h2){
        if(h2 == 1) ans = root->right->val;
        else rec(root->right);
    }
    else {
        if(h1 == 1) ans = root->left->val;
        else rec(root->left);
    }
}
 
int Solution::lastNode(TreeNode* A) {
    if(height(A) == 1) return A->val;
    rec(A);
    return ans;
}

//Method - 3
//TC: O(NlogN)
//SC: O(1)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* A){
    if(A == NULL){
        return 0;
    }
    return 1 + max(height(A -> left), height(A -> right)); //Not required as in a complete binary tree we can find height just by keep going left
}
int Solution::lastNode(TreeNode* A) {
    
    int lht = height(A -> left);
    int rht = height(A -> right);
    
    if(lht == 0){
        return A -> val;
    }
    else if(lht == rht){
        return lastNode(A -> right);
    }
    else{
        return lastNode(A -> left);
    }
}

//Method - 4
//TC: O(logN*logN)
//SC: O(1)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* A){
    if(A == NULL){
        return 0;
    }
    return 1 + height(A -> left);
}
int Solution::lastNode(TreeNode* A) {
    int lht = height(A -> left);
    int rht = height(A -> right);
    if(lht == 0){
        return A -> val;
    }
    else if(lht == rht){
        return lastNode(A -> right);
    }
    else{
        return lastNode(A -> left);
    }
}
