//Method - 1
//Recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseLL(ListNode* temp1,ListNode* temp2,ListNode* temp3, ListNode* &head){
    
    if(temp3 == NULL){
        temp2 -> next = temp1;
        head = temp2;
        return temp1;
    }
    return reverseLL(temp2,temp3,temp3->next,head) -> next = temp1;
}
ListNode* Solution::reverseList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* temp1 = NULL, *temp2 = A, *temp3 = A -> next;
    
    ListNode* head;
    
    reverseLL(temp1,temp2,temp3,head);
    
    return head;
}

//Method - 2
//Iterative
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* temp1 = NULL, *temp2 = A, *temp3 = A -> next;
    
    while(temp3){
        
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    
    temp2 -> next = temp1;
    return temp2;
}

//Method - 3
//Optimal Recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseLL(ListNode* prev, ListNode* curr, ListNode* &head){
    
    if(curr == NULL){
        head = prev;
        return prev;
    }
    
    return reverseLL(curr,curr->next,head) -> next = prev;
}
ListNode* Solution::reverseList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* head;
    
    reverseLL(NULL,A,head);
    
    return head;
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
ListNode* reverse(ListNode* &head, ListNode* A){

    if(A -> next == NULL){
        head = A;
        return A;
    }
    ListNode* temp = reverse(head, A -> next);
    if(head == NULL){
        head = temp;
    }
    A -> next = NULL;
    temp -> next = A;
    return A;
}
ListNode* Solution::reverseList(ListNode* A) {

    if(A == NULL){
        return A;
    }
    ListNode* head;
    reverse(head, A);
    return head;
}
