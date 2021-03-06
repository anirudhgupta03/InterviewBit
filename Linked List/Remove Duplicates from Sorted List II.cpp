/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode *ptr1 = NULL, *ptr2 = A, *ptr3 = A -> next;
    
    while(ptr3 != NULL){
        
        if(ptr2 -> val == ptr3 -> val){
            
            while(ptr3 != NULL && ptr3 -> val == ptr2 -> val){
                ptr3 = ptr3 -> next;
            }
            
            if(ptr1 == NULL){
                A = ptr3;
            }
            else{
                ptr1 -> next = ptr3;
            }
            ptr2 = ptr3;
            if(ptr3 != NULL){
                ptr3 = ptr3 -> next;
            }
        }
        else{
            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr3 -> next;
        }
        
    }
    return A;
}
