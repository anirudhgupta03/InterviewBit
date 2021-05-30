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
    
    if(l.size()==0 || r.size()==0) return 0;
    
    int lval = l.top()->val, rval = r.top()->val;
    
    while(lval < rval){
        
        //cout << lval << " " << rval << endl;
        if(lval + rval == B && lval != rval){
            return true;
        }
        else if(lval + rval < B){
            
            TreeNode* curr = l.top();
            l.pop();
            curr = curr -> right;
            while(curr != NULL){
                l.push(curr);
                curr = curr -> left;
            }
            lval = l.top()->val;
        }
        else{
            TreeNode* curr = r.top();
            r.pop();
            
            curr = curr -> left;
            
            while(curr != NULL){
                r.push(curr);
                curr = curr -> right;
            }
            rval = r.top()->val;
        }
    }
    return false;
}
