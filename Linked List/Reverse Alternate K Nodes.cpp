//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL || B == 1){
        return A;
    }
    
    ListNode *temp1 = NULL, *temp2 = A, *temp3 = A -> next, *temp4, *temp5;
    temp4 = temp1;
    temp5 = temp2;
    
    int p = 0;
    while(temp3 != NULL){
        
        if(p % 2 == 0){
            int count = 1;
            while(count != B){
                temp2 -> next = temp1;
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3 -> next;
                count++;
            }
            temp2 -> next = temp1;
            if(temp4 == NULL){
                A = temp2;
            }
            else{
                temp4 -> next = temp2;
            }
            temp5 -> next = temp3;
            p++;
        }
        else{
            int count = 1;
            while(count != B){
                temp3 = temp3 -> next;
                count++;
            }
            temp4 = temp3;
            temp3 = temp3 -> next;
            temp5 = temp3;
            temp2 = temp3;
            temp1 = NULL;
            if(temp2 != NULL) temp3 = temp2 -> next;
            p++;
        }
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
ListNode* Solution::solve(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL || B == 1){
        return A;
    }
    ListNode* ptr1 = NULL, *ptr2 = A, *ptr3 = A -> next;
    
    ListNode* prev = NULL, *start = A;
    
    int count = 0;
    
    bool flag = 1;
    
    while(ptr3){
        
        if(flag){
            count = 0;
            while(count != B - 1){
                ptr2 -> next = ptr1;
                ptr1 = ptr2;
                ptr2 = ptr3;
                ptr3 = ptr3 -> next;
                count++;
            }
            ptr2 -> next = ptr1;
            
            if(prev == NULL) A = ptr2;
            else prev -> next = ptr2;
            
            start -> next = ptr3;
            flag = 0;
        }
        else{
            
            count = 0;
            while(count != B - 1){
                ptr3 = ptr3 -> next;
                count++;
            }
            prev = ptr3;
            
            if(ptr3 -> next != NULL){
                ptr1 = NULL;
                ptr2 = ptr3 -> next;
                ptr3 = ptr2 -> next;
            }
            else{
                break;
            }
            start = ptr2;
            flag = 1;
        }
    }
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
ListNode* Solution::solve(ListNode* A, int B) {

    ListNode* dummy = new ListNode(-1);
    dummy -> next = A;

    ListNode* pre = dummy, *curr = A;
    int k;
    bool flag = true;
    while(curr){
        if(flag){
            k = B - 1;
            ListNode* temp1 = NULL, *temp2 = curr, *temp3 = curr -> next;
            while(k--){
                temp2 -> next = temp1;
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3 -> next;
            }
            temp2 -> next = temp1;
            pre -> next = temp2;
            pre = curr;
            curr -> next = temp3;
            curr = temp3;
            flag = false;
        }
        else{
            k = B;
            while(k--){
                pre = curr;
                curr = curr -> next;
            }
            flag = true;
        }
    }
    return dummy -> next;
}
