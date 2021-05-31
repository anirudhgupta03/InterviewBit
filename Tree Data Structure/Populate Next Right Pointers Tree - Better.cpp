//Ref: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37472/A-simple-accepted-solution Comments
//Ref: https://www.youtube.com/watch?v=KX6gz1-pjg0
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    
    if(A == NULL){
        return;
    }
    
    queue<TreeLinkNode*> q;
    q.push(A);
    q.push(NULL);
    
    while(!q.empty()){
        
        TreeLinkNode* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            curr -> next = q.front();
            if(curr -> left != NULL){
                q.push(curr->left);
            }
            if(curr -> right != NULL){
                q.push(curr -> right);
            }
        }
    }
}
