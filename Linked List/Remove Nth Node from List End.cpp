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
