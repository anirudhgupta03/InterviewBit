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
