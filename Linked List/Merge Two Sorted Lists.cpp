//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    if(A == NULL){
        return B;
    }
    else if(B == NULL){
        return A;
    }
    
    ListNode *ptr1 = A, *ptr2 = B, *temp ,*start;
    
    if(ptr1 -> val < ptr2 -> val){
        start = ptr1;
        ptr1 = ptr1 -> next;
    }
    else{
        start = ptr2;
        ptr2 = ptr2 -> next;
    }
    temp = start;
    while(ptr1 && ptr2){
        if(ptr1 -> val < ptr2 -> val){
            temp -> next = ptr1;
            temp = temp -> next;
            ptr1 = ptr1 -> next;
        }
        else{
            temp -> next = ptr2;
            temp = temp -> next;
            ptr2 = ptr2 -> next;
        }
    }
    if(ptr1 != NULL){
        temp -> next = ptr1;
    }
    else if(ptr2 != NULL){
        temp -> next = ptr2;
    }
    return start;
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
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    if(A == NULL) return B;
    if(B == NULL) return A;
  
    if(B -> val < A -> val){
        swap(A,B);
    }
    
    ListNode* temp, *prev = NULL, *head = A;
    
    while(A && B){
        
        if(B -> val < A -> val){
            temp = B;
            B = B -> next;
            temp -> next = A;
            prev -> next = temp;
            prev = temp;            //Important
        }
        else{
            prev = A;
            A = A -> next;
        }
    }
    
    while(B){
        prev -> next = B;
        prev = B;
        B = B -> next;
    }
    return head;
}

//Method - 3
//Using Dummy Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;
    
    ListNode* dummy = new ListNode(-1);
    ListNode* ptr = dummy;
    while(A && B){
        if(A -> val < B -> val){
            ptr -> next = A;
            ptr = A;
            A = A -> next;
        }
        else{
            ptr -> next = B;
            ptr = B;
            B = B -> next;
        }
    }
    if(A) ptr -> next = A;
    if(B) ptr -> next = B;
    return dummy -> next;
}
