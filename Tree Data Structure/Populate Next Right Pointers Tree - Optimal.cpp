/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//This solution by takes only O(1) Space and O(n) Time
void Solution::connect(TreeLinkNode* A) {
    
    TreeLinkNode* curr = A;
    TreeLinkNode* prev = NULL;
    TreeLinkNode* leftmost = NULL;
    
    while(curr != NULL){
        
        while(curr != NULL){
            
            if(curr -> left != NULL){
                
                if(prev != NULL){
                    prev -> next = curr -> left;
                }
                else{
                    leftmost = curr -> left;
                }
                prev = curr -> left;
            }
            
            if(curr -> right != NULL){
                
                if(prev != NULL){
                    prev -> next = curr -> right;
                }
                else{
                    leftmost = curr -> right;
                }
                prev = curr -> right;
            }
            
            curr = curr -> next;
        }
        curr = leftmost;
        prev = NULL;
        leftmost = NULL;
    }
}
