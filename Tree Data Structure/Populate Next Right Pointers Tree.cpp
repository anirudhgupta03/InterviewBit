/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//This Solution takes O(n) Space and O(n) time (Queue)
void Solution::connect(TreeLinkNode* A) {
    
        if(A == NULL){
            return;
        }
        
        queue<pair<TreeLinkNode*,int>> q;
        q.push({A,0});
        
        while(!q.empty()){

            TreeLinkNode* curr = q.front().first;
            int d = q.front().second;
            q.pop();
            
            while(!q.empty() && q.front().second == d){
                
                if(curr -> left != NULL){
                    q.push({curr->left,d+1});
                }
                if(curr -> right != NULL){
                    q.push({curr->right,d+1});
                }
                curr -> next = q.front().first;
                curr = q.front().first;
                q.pop();
            }
            
            curr -> next = NULL;
            if(curr -> left != NULL){
                q.push({curr->left,d+1});
            }
            if(curr -> right != NULL){
                q.push({curr->right,d+1});
            }
        }
}
