/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    int p1 = 1;
    
    ListNode *ptr1 = A, *ptr2 = NULL;
    
    while(p1 != B){
        ptr2 = ptr1;
        ptr1 = ptr1 -> next;
        p1++;
    }
    ListNode *temp1 = NULL, *temp2 = ptr1, *temp3 = ptr1 -> next;
    
    while(p1 != C){
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
        p1++;
    }
    temp2 -> next = temp1;
    
    if(ptr2 != NULL){
        ptr2 -> next -> next = temp3;
        ptr2 -> next = temp2;
        return A;
    }
    else{
        A -> next = temp3;
        return temp2;
    }
}
