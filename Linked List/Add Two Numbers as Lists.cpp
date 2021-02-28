/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    int len1 = 0, len2 = 0, a, b;
    
    ListNode* temp1 = A, *temp2 = B;
    
    while(temp1!= NULL){
        len1++;
        temp1 = temp1 -> next;
    }
    while(temp2!=NULL){
        len2++;
        temp2 = temp2 -> next;
    }
    
    int carry = 0;
    
    if(len1 >= len2){
        temp1 = A;
        temp2 = B;
        while(temp2 != NULL){
            a = temp1 -> val, b = temp2 -> val;
            temp1 -> val = (a + b + carry)%10;
            carry = (a + b + carry)/10;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp1 != NULL){
            a = temp1 -> val;
            temp1 -> val = (a + carry)%10;
            carry = (a + carry)/10;
            temp1 = temp1 -> next;
        }
        temp1 = A;
        while(temp1->next != NULL){
            temp1 = temp1 -> next;
        }
        if(carry != 0){
            temp1 -> next = B;
            B->val = carry;
            B -> next = NULL;
        }
        return A;
    }
    else{
        temp1 = A;
        temp2 = B;
        while(temp1 != NULL){
            a = temp1 -> val, b = temp2 -> val;
            temp2 -> val = (a + b + carry)%10;
            carry = (a + b + carry)/10;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp2 != NULL){
            a = temp2 -> val;
            temp2 -> val = (a + carry)%10;
            carry = (a + carry)/10;
            temp2 = temp2 -> next;
        }
        temp2 = B;
        while(temp2->next != NULL){
            temp2 = temp2 -> next;
        }
        if(carry != 0){
            temp2 -> next = A;
            A->val = carry;
            A -> next = NULL;
        }
        return B;
    }
}
