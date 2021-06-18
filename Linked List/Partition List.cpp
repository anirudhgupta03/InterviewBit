/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode *temp = A;
    int pos = 0,count = 0;
    
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    temp = A;
    while(temp != NULL){
        
        pos++;
        if(temp -> val >= B){
            break;
        }
        temp = temp -> next;
        
    }
    if(pos == count){
        return A;
    }
    
    
    int p = 0;
    ListNode *ptr1 = NULL, *ptr2 = A;
    
    while(p != pos-1){
        ptr1 = ptr2;
        ptr2 = ptr2 -> next;
        p++;
    }
    
    ListNode *ptr3 = ptr2, *ptr4 = ptr2 ->next;
    
    while(ptr4 != NULL){
        
        if(ptr4 -> val < B){
            if(ptr1 == NULL){
                ptr1 = ptr4;
                A = ptr1;
            }
            else{
                ptr1 -> next = ptr4;
                ptr1 = ptr1 -> next;
            }
            ptr3 -> next = ptr4 -> next;
            ptr4 = ptr4 -> next;
        }
        else{
            ptr3 = ptr4;
            ptr4 = ptr4 -> next;
        }
    }
    
    if(ptr1 != NULL){
        ptr1 -> next = ptr2;
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
ListNode* Solution::partition(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* ptr1 = A, *ptr2 = A, *prev1 = NULL, *prev2 = NULL, *temp;
    
    bool flag = false;
    
    while(ptr1){
        
        if(ptr1 -> val >= B && !flag){
            prev2 = prev1;
            ptr2 = ptr1;
            flag = true;
            prev1 = ptr1;
            ptr1 = ptr1 -> next;
        }
        else if(ptr1 -> val < B && flag){
            if(prev2 == NULL){
                temp = ptr1;
                ptr1 = ptr1 -> next;
                prev1 -> next = ptr1;
                A = temp;
                temp -> next = ptr2;
            }
            else{
                temp = ptr1;
                ptr1 = ptr1 -> next;
                prev1 -> next = ptr1;
                temp -> next = ptr2;
                prev2 -> next = temp;
            }
            prev2 = temp;
        }
        else{
            prev1 = ptr1;
            ptr1 = ptr1 -> next;
        }
    }
    
    return A;
}
