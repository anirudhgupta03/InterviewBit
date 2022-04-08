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
bool findPath(TreeNode* A, int value, vector<int> &temp){
    if(A == NULL){
        return false;
    }
    temp.push_back(A -> val);
    if(A -> val == value){
        return true;
    }
    bool flag = false;
    flag = findPath(A -> left, value, temp);
    if(flag) return true;
    
    flag = findPath(A -> right, value, temp);
    if(flag) return true;
    temp.pop_back();
    
    return false;
}
int Solution::lca(TreeNode* A, int B, int C) {

    vector<int> path1, path2;
    findPath(A, B, path1);
    findPath(A, C, path2);

    if(path1.back() != B || path2.back() != C){
        return -1;
    }
    int common = -1;
    for(int i = 0; i < min(path1.size(), path2.size()); i++){
        if(path1[i] != path2[i]){
            break;
        }
        else{
            common = path1[i];
        }
    }
    return common;
}

//Ref: https://www.youtube.com/watch?v=T6Jr-Q6bvSU
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
bool find(TreeNode* root, int value){
    
    if(root == NULL){
        return false;
    }
    
    if(root -> val == value){
        return true;
    }
    
    return find(root->left,value) || find(root->right,value);
}
TreeNode* solve(TreeNode* root, int B, int C){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root -> val == B || root -> val == C){
        return root;
    }
    
    TreeNode* l = solve(root->left,B,C);
    TreeNode* r = solve(root->right,B,C);
    
    if(l != NULL && r != NULL){
        return root;
    }
    if(l != NULL){
        return l;
    }
    if(r != NULL){
        return r;
    }
    return NULL;
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    if(find(A,B) && find(A,C)){
        return solve(A,B,C)->val;
    }
    return -1;
}

//Method - 3
//Optimal
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(TreeNode* A, int B, int C, bool &f1, bool &f2){

    if(A == NULL){
        return NULL;
    }

    if(A -> val == B){
        f1 = true;
    }
    if(A -> val == C){
        f2 = true;
    }
    TreeNode* l = solve(A -> left, B, C,f1,f2);
    TreeNode* r = solve(A -> right, B, C,f1,f2);

    if(A -> val == B || A -> val == C){
        return A;
    }
    
    if(l && r){
        return A;
    }
    if(l) return l;
    if(r) return r;
    return NULL;
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    bool f1 = false, f2 = false;
    
    TreeNode* temp = solve(A,B,C,f1,f2);

    if(f1 && f2)
    return temp -> val;
    
    return -1;
}
