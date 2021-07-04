/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    
    RandomListNode* temp1, *temp2, *temp3;

    temp1 = A;

    while(temp1 != NULL){
        temp2 = temp1;
        temp1 = temp1 -> next;
        temp3 = new RandomListNode(temp2 -> label);
        temp2 -> next = temp3;
        temp3 -> next = temp1;
    }
    
    
    temp1 = A;
    while(temp1 != NULL){
        temp2 = temp1 -> next;
        if(temp1 -> random != NULL){
            temp2 -> random = temp1 -> random -> next;
        }
        temp1 = temp2 -> next;
    }
    
    RandomListNode* head, *prev = NULL;

    temp1 = A, temp2 = A -> next;

    while(temp1){
        temp1 -> next = temp2 -> next;
        temp1 = temp2 -> next;
        if(prev == NULL){
            head = temp2;
        }
        prev = temp2;
        if(temp1 != NULL){
            temp2 -> next = temp1 -> next;
            temp2 = temp1 -> next;
        }
    }

    return head;
}
