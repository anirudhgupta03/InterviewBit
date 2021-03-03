/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    
    ListNode* hare = A, *tortoise = A;
    
    do{
        if(hare == NULL || hare -> next == NULL){ 
            return NULL;
        }
        hare = hare -> next -> next;
        tortoise = tortoise -> next;
    }while(hare != tortoise);
    
    hare = A;
    while(hare != tortoise)
    {
        hare = hare -> next;
        tortoise = tortoise -> next;
    }
    
    return hare;
}
