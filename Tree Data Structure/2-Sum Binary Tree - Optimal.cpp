//Ref: https://www.youtube.com/watch?v=nNwTWOhrffo
//TC - O(N)
//SC - O(logN)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    
    stack<TreeNode*> l,r;
    
    TreeNode* temp = A;
    
    while(temp != NULL){
        l.push(temp);
        temp = temp -> left;
    }
    
    temp = A;
    
    while(temp != NULL){
        r.push(temp);
        temp = temp -> right;
    }
    
    while(!l.empty() && !r.empty()){
    
        TreeNode* lefttop = l.top();
        TreeNode* righttop = r.top();
        
        if(lefttop->val + righttop->val == B && lefttop != righttop){
            return true;
        }
        else if(lefttop->val + righttop->val < B){
            l.pop();
            lefttop = lefttop -> right;
            while(lefttop != NULL){
                l.push(lefttop);
                lefttop = lefttop -> left;
            }
        }
        else{
            r.pop();
            righttop = righttop -> left;
            while(righttop != NULL){
                r.push(righttop);
                righttop = righttop -> right;
            }
        }
    }
    return false;
}
