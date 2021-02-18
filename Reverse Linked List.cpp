/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    
    ListNode* temp1 = NULL;
    
    ListNode* temp2 = A ;
    
    ListNode* temp3 = A -> next;
    
    while(temp3 != NULL){
        
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    
    temp2 -> next = temp1;
    return temp2;
}
