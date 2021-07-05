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
void solve(TreeNode* A, int &ans, int count){
    
    if(A == NULL){
        return;
    }
    if(A -> left == NULL && A->right == NULL){
        count++;
        ans = min(ans,count);
        return;
    }
    
    count++;
    solve(A->left,ans,count);
    solve(A->right,ans,count);
}
int Solution::minDepth(TreeNode* A) {
    
    int ans = INT_MAX;
    
    int count = 0;
    
    solve(A,ans,count);
    
    return ans;
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
int Solution::minDepth(TreeNode* A) {

    if(A == NULL){
        return 0;
    }

    int ldepth = minDepth(A -> left);
    int rdepth = minDepth(A -> right);

    if(ldepth == 0){
        return rdepth + 1;
    }
    else if(rdepth == 0){
        return ldepth + 1;
    }
    else{
        return min(ldepth,rdepth) + 1;
    }
}
