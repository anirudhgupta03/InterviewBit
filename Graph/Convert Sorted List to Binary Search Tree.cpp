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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* buildTree(int l, int r, vector<int> &v){

    if(l > r){
        return NULL;
    }
    
    int mid = (l + r)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root -> left = buildTree(l,mid-1,v);
    root -> right = buildTree(mid+1,r,v);

    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    
    ListNode* temp = A;
    vector<int> v;

    while(temp){
        v.push_back(temp -> val);
        temp = temp -> next;
    }
    return buildTree(0,v.size()-1,v);
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A){
    
    if(A == NULL){
        return NULL;
    }
    
    if(A -> next == NULL){
        return new TreeNode(A -> val);
    }
    ListNode* slow = A, *fast = A, *prev;
    
    while(fast != NULL && fast -> next != NULL){
        prev = slow;
        slow = slow -> next; 
        fast = fast -> next -> next;
    }
    
    prev -> next = NULL;
    TreeNode* root = new TreeNode(slow -> val);
    root -> left = sortedListToBST(A);
    root -> right = sortedListToBST(slow -> next);
    
    return root;
}
