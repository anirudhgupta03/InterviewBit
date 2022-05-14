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

//Method - 2
//Optimal Approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    ListNode* temp1 = A, *temp2 = B, *prev = NULL;
    
    int carry = 0;
    
    while(temp1 && temp2){
        
        int t = (temp1 -> val + temp2 -> val + carry);
        temp1 -> val = t%10;
        carry = t/10;
        prev = temp1;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    
    if(temp1 != NULL){
        while(temp1){
            int t = (temp1 -> val + carry);
            temp1 -> val = t%10;
            carry = t/10;
            prev = temp1;
            temp1 = temp1 -> next;
        }
        if(carry != 0){
            prev -> next = new ListNode(carry);
        }
        return A;
    }
    
    if(temp2 != NULL){
        prev -> next = temp2;
        while(temp2){
            int t = (temp2 -> val + carry);
            temp2 -> val = t % 10;
            carry = t/10;
            prev = temp2;
            temp2 = temp2 -> next;
        }
        if(carry != 0){
            prev -> next = new ListNode(carry);
        }
        return A;
    }
    
    if(carry != 0){
        prev -> next = new ListNode(carry);
    }
    return A;
}

//Method - 3
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    if(A == NULL) return B;
    if(B == NULL) return A;

    ListNode* pre = NULL;
    int carry = 0, sum;
    ListNode* head = A;

    while(A && B){
        sum = A -> val + B -> val + carry;
        A -> val = sum % 10;
        carry = sum/10;
        pre = A;
        A = A -> next;
        B = B -> next;
    }
    if(carry){
        if(A){
            while(A && carry){
                sum = A -> val + carry;
                A -> val = sum % 10;
                carry = sum/10;
                pre = A;
                A = A -> next;
            }
            if(carry){
                pre -> next = new ListNode(carry);
            }
        }
        else if(B){
            pre -> next = B;
            while(B && carry){
                sum = B -> val + carry;
                B -> val = sum % 10;
                carry = sum/10;
                pre = B;
                B = B -> next;
            }
            if(carry){
                pre -> next = new ListNode(carry);
            }
        }
        else{
            pre -> next = new ListNode(carry);
        }
    }
    else{
        if(B){
            pre -> next = B;
        }
    }
    return head;
}
