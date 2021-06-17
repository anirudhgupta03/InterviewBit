/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A == NULL || B == 0)
    {
        return A;
    }
    int count = 0;
    
    ListNode* temp = A;
    
    while(temp!= NULL)
    {
        count++;
        temp = temp -> next;
    }
    
    int l = count - B + 1;  //Position from left
    
    if(l <= 1)
    {
        temp = A;
        temp = temp -> next;
        A-> next = NULL;
        A = temp;
        return A;
    }
    
    count = 1;
    temp = A;
    
    while(count != l - 1)
    {
        count++;
        temp = temp -> next;
    }
    ListNode* temp2 = temp->next->next;
    temp->next = temp2;
    return A;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=Lhu3MsXZy-Q&t=512s
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    if(A == NULL || A -> next == NULL){
        return NULL;
    }
    ListNode* p1 = A, *p2 = A;
    
    while(p1 && B){
        p1 = p1 -> next;
        B--;
    }
    
    if(p1 == NULL){
        return A -> next;
    }
    while(p1 -> next){
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    
    if(p2 == A){
        return A -> next;
    }
    p2 -> next = p2 -> next -> next;
    return A;
}
