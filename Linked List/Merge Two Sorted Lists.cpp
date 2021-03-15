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