//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    ListNode* ptr1 = A -> next, *ptr2, *temp;
  
    while(ptr1){
        ptr2 = A;
        while(ptr2 -> next != ptr1 && ptr2 -> val < ptr1 -> val){
            ptr2 = ptr2 -> next;
        }
        
        int temp1 = ptr1 -> val, temp2;
        if(ptr2 -> val > ptr1 -> val){
            while(ptr2 != ptr1){
                temp2 = ptr2 -> val;
                ptr2 -> val = temp1;
                temp1 = temp2;
                ptr2 = ptr2 -> next;
            }
            ptr2 -> val = temp1;
        }
        ptr1 = ptr1 -> next;
    }
    return A;
}

//Method - 2
//Using Dummy Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {

    if(A == NULL || A -> next == NULL){
        return A;
    }

    ListNode* dummy = new ListNode(-1);
    dummy -> next = A;
    
    ListNode* ptr1 = A -> next, *ptr2, *pre1, *pre2 = A;
    while(ptr1){
        ptr2 = dummy -> next;
        pre1 = dummy;
        while(ptr2 -> next != ptr1 && ptr1 -> val >= ptr2 -> val){
            pre1 = ptr2;
            ptr2 = ptr2 -> next;
        }
        if(ptr2 -> val > ptr1 -> val){
            pre2 -> next = ptr1 -> next;
            ptr1 -> next = ptr2;
            pre1 -> next = ptr1;
            ptr1 = pre2 -> next;
        }
        else{
            pre2 = ptr1;
            ptr1 = ptr1 -> next;
        }
    }
    return dummy -> next;
}
