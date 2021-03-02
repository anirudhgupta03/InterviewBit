ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* ptr1 = A, *ptr2 = A -> next;
    
    while(ptr2 != NULL){
        
        if(ptr2 -> val == ptr1 -> val){
            ptr1 -> next = ptr2 -> next;
            ptr2 -> next = NULL;
            ptr2 = ptr1 -> next;
        }
        else{
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
    }
    
    return A;
}
