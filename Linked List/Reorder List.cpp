/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL || A -> next -> next == NULL){
        return A;
    }
    
    ListNode* temp = A;
    int count = 0;
    
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    
    int p = 1;
    temp = A;
    while(p != count/2){
        temp = temp -> next;
        p++;
    }
    
    ListNode *temp1 = NULL, *temp2 = temp -> next, *temp3 = temp -> next -> next;
    
    temp -> next = NULL;
    
    while(temp3 != NULL){
        
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
        
    }
    temp2 -> next = temp1;
    
    ListNode *ptr1 = A, *ptr2 = temp2, *ptr3 = A;
    
    ptr1 = ptr1 -> next;
    
    while(ptr1 && ptr2){
        
        ptr3 -> next = ptr2;
        ptr2 = ptr2 -> next;
        ptr3 = ptr3 -> next;
        
        ptr3 -> next = ptr1;
        ptr1 = ptr1 -> next;
        ptr3 = ptr3 -> next;
        
    }
    ptr3 -> next = ptr2;
    return A;
}
