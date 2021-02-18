/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    if(A == NULL || A->next == NULL){
        return 1;
    }
    
    ListNode* temp1 = A, *temp2;
    
    int n = 0;
    
    while(temp1 != NULL){
        n++;
        temp1 = temp1 -> next;
    }
    
    temp1 = A;
    int count = 0;
    
    if(n % 2 == 0){
        
        while(count != n/2 - 1){
            count++;
            temp1 = temp1 -> next;
        }
    }
    else{
        
        while(count != n/2){
            count++;
            temp1 = temp1 -> next;
        }
    }
    
    ListNode* prev = NULL, *curr = temp1 -> next, *next = temp1->next->next;
    
    while(next != NULL){
        curr -> next = prev;
        prev = curr;
        curr = next;
        next = next -> next;
    }
    
    curr -> next = prev;
    temp1 -> next = curr;
    
    temp2 = A;
    temp1 = temp1 -> next;
    
    while(temp1 != NULL){
        if(temp2 -> val != temp1 -> val){
            return 0;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return 1;
}
