//Method - 1
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

//Method - 2
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {

    queue<TreeLinkNode*> q;

    q.push(A);

    while(!q.empty()){

        int sz = q.size();

        while(sz != 1){

            TreeLinkNode* temp1 = q.front();
            q.pop();
            TreeLinkNode* temp2 = q.front();
            temp1 -> next = temp2;

            if(temp1 -> left) q.push(temp1 -> left);
            if(temp1 -> right) q.push(temp1 -> right);
            sz--;
        }
        TreeLinkNode* temp1 = q.front();
        q.pop();
        if(temp1 -> left) q.push(temp1 -> left);
        if(temp1 -> right) q.push(temp1 -> right);
        temp1 -> next = NULL;
    }
}

//Method - 3
//Best
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
    while(!q.empty()){
        int sz = q.size();
        TreeLinkNode* pre = NULL;
        while(sz--){
            TreeLinkNode* curr = q.front();
            q.pop();
            if(pre != NULL){
                pre -> next = curr;
            }
            pre = curr;
            if(curr -> left) q.push(curr -> left);
            if(curr ->  right) q.push(curr -> right);
        }
    }
}

//Method - 4
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

//Method - 5
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

//Method - 6
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
    
    while(!q.empty()){
        int sz = q.size();
        TreeLinkNode* pre = q.front();
        q.pop();
        if(pre -> left) q.push(pre -> left);
        if(pre -> right) q.push(pre -> right);
        
        sz--;
        while(sz--){
            TreeLinkNode* curr = q.front();
            q.pop();
            pre -> next = curr;
            pre = curr;
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
        }
    }
}
