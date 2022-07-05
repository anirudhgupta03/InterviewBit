//Method - 1
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

//Method - 2
//Using slow & fast pointers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* slow){
    if(slow == NULL || slow -> next == NULL){
        return slow;
    }
    ListNode* temp1 = NULL, *temp2 = slow, *temp3 = slow -> next;
    while(temp3){
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    temp2 -> next = temp1;
    return temp2;
}
int Solution::lPalin(ListNode* A) {
    if(A == NULL || A -> next == NULL){
        return 1;
    }
    ListNode* slow = A, *fast = A, *pre = NULL;
    while(slow && fast && fast -> next){
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    pre -> next = NULL;
    ListNode* B = reverse(slow);

    while(A && B){
        if(A -> val != B -> val){
            return false;
        }
        A = A -> next;
        B = B -> next;
    }
    return true;
}
