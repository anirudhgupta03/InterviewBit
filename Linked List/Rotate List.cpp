//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    if(A == NULL){
        return A;
    }
    ListNode* p1 = A;
    
    int count = 0;
    
    while(p1 -> next != NULL){
        count++;
        p1 = p1 -> next;
    }
    count++;
    p1 -> next = A;
    
    int l = count - B % count;
    
    count = 0;
    p1 = A;
    
    while(count != l){
        count++;
        p1 = p1 -> next;
    }
    
    A = p1;
    
    count = l + B;
    int t = 0;
    while(t != count - 1){
        p1 = p1->next;
        t++;
    }
    p1 -> next = NULL;
    return A;
}

//Method - 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {

    if(A == NULL || A -> next == NULL){
        return A;
    }

    int len = 0;
    ListNode* temp = A;

    while(temp){
        len++;
        temp = temp -> next;
    }
    ListNode* dummy = new ListNode(-1);
    dummy -> next = A;

    ListNode* slow = dummy, *fast = dummy;  

    B %= len;
    while(B--){
        fast = fast -> next;
    }
    while(fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }
    fast -> next = dummy -> next;
    dummy -> next = slow -> next;
    slow -> next = NULL;
    return dummy -> next;
} 

//Method - 3
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {

    if(A == NULL || A -> next == NULL || B == 0){
        return A;
    }
    int len = 0;
    ListNode* temp = A, *pre = NULL;
    while(temp){
        len++;
        pre = temp;
        temp = temp -> next;
    }
    pre -> next = A;
    B = B%len;
    B = len - B;
    B--;
    temp = A;
    while(B--){
        temp = temp -> next;
    }
    ListNode* head = temp -> next;
    temp -> next = NULL;
    return head;
}

//Method - 4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    ListNode* node = A;
    
    while(node -> next){
        node = node -> next;
    }
    node -> next = A;
    
    node = A;
    while(B--){
        node = node -> next;
    }
    
    ListNode* temp = A;
    
    while(node -> next != A){
        temp = temp -> next;
        node = node -> next;
    }
    
    ListNode* root = temp -> next;
    temp -> next = NULL;
    return root;
}
