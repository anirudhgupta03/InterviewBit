//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL || B == 1){
        return A;
    }
    
    ListNode *temp1 = NULL, *temp2 = A, *temp3 = A -> next, *temp4, *temp5;
    
    int count = 1;
    while(count != B){
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
        count++;
    }
    temp2 -> next = temp1;
    temp4 = A;
    temp5 = temp3;
    A = temp2;
    
    while(temp3 != NULL){
        temp1 = NULL;
        temp2 = temp3;
        temp3 = temp3 -> next;
        count = 1;
        while(count != B){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
            count++;
        }
        temp2 -> next = temp1;
        temp4 -> next = temp2;
        temp4 = temp5;
        temp5 = temp3;
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
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL || B == 1){
        return A;
    }
    ListNode* start = NULL, *end = NULL;
    
    ListNode* ptr1 = NULL, *ptr2 = A, *ptr3 = A -> next;
    
    ListNode* begin;
    
    int count = B;
    
    while(ptr3){
        count = B;
        begin = ptr2;
        while(count != 1){
            ptr2 -> next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr3 -> next;
            count--;
        }
        ptr2 -> next = ptr1;
        end = ptr2;
        
        if(start == NULL){
            A = end;
        }
        else{
            start -> next = end;
        }
        start = begin;
        ptr1 = NULL;
        ptr2 = ptr3;
        
        if(ptr3 != NULL){
            ptr3 = ptr3 -> next;
        }
    }
    return A;
}
