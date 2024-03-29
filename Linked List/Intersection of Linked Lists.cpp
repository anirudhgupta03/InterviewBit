//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    set<ListNode*> s;
    
    while(A != NULL){
        s.insert(A);
        A = A -> next;
    }
    
    while(B != NULL){
        if(s.find(B) != s.end()){
            return B;
        }
        B = B -> next;
    }
    return NULL;
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

//Method - 3
//Ref: https://www.youtube.com/watch?v=u4FWXfgS8jw
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
   
   int len1 = 0, len2 = 0;
   
   ListNode* temp1 = A, *temp2 = B;
   
   while(temp1){
       len1++;
       temp1 = temp1 -> next;
   }
   while(temp2){
       len2++;
       temp2 = temp2 -> next;
   }
   
   if(len2 > len1){
       swap(len1,len2);
       swap(A,B);
   }
   
   temp1 = A;
   while(len1 != len2){
       temp1 = temp1 -> next;
       len1--;
   }
   temp2 = B;
   while(temp1 && temp2){
       if(temp1 == temp2){
           return temp1;
       }
       temp1 = temp1 -> next;
       temp2 = temp2 -> next;
   }
   
   return NULL;
}

//Method - 4
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    int len1 = 0, len2 = 0;
    ListNode* temp = A;
    while(temp){
        len1++;
        temp = temp -> next;
    }
    temp = B;
    while(temp){
        len2++;
        temp = temp -> next;
    }
    while(len1 > len2){
        A = A -> next;
        len1--;
    }
    while(len2 > len1){
        B = B -> next;
        len2--;
    }
    while(A != B){
        A = A -> next;
        B = B -> next;
    }
    return A;
}
