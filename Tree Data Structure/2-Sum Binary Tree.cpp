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
void solve(TreeNode* root, unordered_map<int,int> &umap){
    
    if(root == NULL){
        return;
    }
    
    umap[root->val]++;
    solve(root->left,umap);
    solve(root->right,umap);
}
int Solution::t2Sum(TreeNode* A, int B) {
    
    unordered_map<int,int> umap;
    
    solve(A,umap);
    
    unordered_map<int,int> :: iterator it;
    
    for(it = umap.begin(); it!= umap.end(); it++){
        
        if(umap.find(B - it->first) != umap.end() && umap.find(B - it->first) != it){
            return 1;
        }
    }
    return 0;
}

//Method - 2
//Valid only when all values are distinct
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

//Method - 3
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

//Method - 4
//Best
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

    stack<TreeNode*> lst, rst;

    TreeNode* temp = A;
    while(temp){
        lst.push(temp);
        temp = temp -> left;
    }

    temp = A;
    while(temp){
        rst.push(temp);
        temp = temp -> right;
    }

    while(!lst.empty() && !rst.empty()){

        TreeNode* l = lst.top(), *r = rst.top();
        int lval = l -> val, rval = r -> val;

        if(l == r) break;

        if(l != r && lval + rval == B){
            return 1;
        }
        else if(lval + rval < B){
            lst.pop();
            l = l -> right;
            while(l){
                lst.push(l);
                l = l -> left;
            }
        }
        else if(lval + rval > B){
            rst.pop();
            r = r -> left;
            while(r){
                rst.push(r);
                r = r -> right;
            }
        }
    }
    return 0;
}
