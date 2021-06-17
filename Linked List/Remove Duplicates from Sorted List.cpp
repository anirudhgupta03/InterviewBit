//Method - 1
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

//Method - 2
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
    ListNode* start = A;
    
    ListNode* temp = A -> next;
    
    int value = A -> val;
    
    while(temp){
        
        if(temp -> val != value){
            start -> next = temp;
            value = temp -> val;
            start = temp;
        }
        temp = temp -> next;
    }
    start -> next = NULL;
    return A;
}
