//Method - 1
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

//Method - 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(A == NULL || A -> next == NULL || B == C){
        return A;
    }
    
    int pos = 0, len = C - B + 1;
    
    ListNode* temp1 = NULL, *temp2 = A, *temp3 = A -> next;
    
    while(pos != B - 1){
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
        pos++;
    }
    
    ListNode *start = temp1, *end = temp2;
    
    temp1 = NULL;
    while(len != 1){
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
        len--;
    }
    
    temp2 -> next = temp1;
    if(start == NULL){
        A = temp2;
    }
    else{
        start -> next = temp2;
    }
    end -> next = temp3;
    return A;
}

//Method - 3
//Using Dummy Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* dummy = new ListNode(-1);
    dummy -> next = A;
    ListNode* pre = dummy;
    int len = 0;
    
    while(A){
        len++;
        if(len == B){
            ListNode* temp1 = NULL, *temp2 = A, *temp3 = A -> next;
            while(len != C){
                temp2 -> next = temp1;
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3 -> next;
                len++;
            }
            temp2 -> next = temp1;
            pre -> next = temp2;
            A -> next = temp3;
            break;
        }
        else{
            pre = A;
            A = A -> next;
        }
    }
    return dummy -> next;
}
