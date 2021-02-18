/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    ListNode* temp1 = A, *temp2 = B;
    int m = 0, n = 0;
    
    while(temp1 != NULL){
        m++;
        temp1 = temp1 -> next;
    }
    
    while(temp2 != NULL){
        n++;
        temp2 = temp2 ->next;
    }
    int count = 0, diff;
    if(m >= n){
        diff = m - n;
        temp1 = A;
        temp2 = B;
        while(count != diff){
            temp1 = temp1->next;
            count++;
        }
        
        while(temp1 != NULL && temp2 != NULL){
            
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return NULL;
    }
    else{
        diff = n - m;
        temp2 = B;
        temp1 = A;
        while(count != diff){
            temp2 = temp2->next;
            count++;
        }
        
        while(temp1 != NULL && temp2 != NULL){
            
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return NULL;
    }
}
