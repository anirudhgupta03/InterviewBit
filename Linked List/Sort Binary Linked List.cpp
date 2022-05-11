//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
   int c1 = 0;
   ListNode *temp = A;
   
   while(temp != NULL){
       
       if(temp -> val == 0){
           c1++;
       }
       temp = temp -> next;
   }
   
   temp = A;
   int count = 0;
   while(count != c1){
       temp -> val = 0;
       temp = temp -> next;
       count++;
   }
   while(temp != NULL){
       temp -> val = 1;
       temp = temp -> next;
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
ListNode* Solution::solve(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* temp = A;
    int count = 0;
    
    while(temp){
        if(temp -> val == 0){
            count++;
        }
        temp = temp -> next;
    }
    
    ListNode* p1 = A, *p2 = A, *prev = NULL;
    
    while(p2 -> next){
        p2 = p2 -> next;
    }
    
    while(p1){
        if(p1 -> val == 1){
            temp = p1;
            p1 = p1 -> next;
            
            if(prev == NULL){
                A = p1;
            }
            else{
                prev -> next = p1;
            }
            temp -> next = NULL;
            p2 -> next = temp;
            p2 = p2 -> next;
        }
        else{
            prev = p1;
            p1 = p1 -> next;
            count--;
        }
        
        if(count == 0){
            break;
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
ListNode* Solution::solve(ListNode* A) {

    ListNode* dummy = new ListNode(-1);
    dummy -> next = A;

    ListNode* temp = dummy, *pre = dummy;

    while(A && A -> val == 0){
        pre = A;
        temp = temp -> next;
        A = A -> next;
    }

    while(A){
        if(A -> val == 0){
            ListNode* t = A -> next;
            A -> next = NULL;
            pre -> next = t;
            A -> next = temp -> next;
            temp -> next = A;
            temp = temp -> next;
            A = t;
        }
        else{
            pre = A;
            A = A -> next;
        }
    }
    return dummy -> next;
}
