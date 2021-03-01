/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    if(A == NULL){
        return A;
    }
    ListNode* p1 = A;
    
    int count = 0;
    
    while(p1 -> next != NULL){
        count++;
        p1 = p1 -> next;
    }
    count++;
    p1 -> next = A;
    
    int l = count - B % count;
    
    count = 0;
    p1 = A;
    
    while(count != l){
        count++;
        p1 = p1 -> next;
    }
    
    A = p1;
    
    count = l + B;
    int t = 0;
    while(t != count - 1){
        p1 = p1->next;
        t++;
    }
    p1 -> next = NULL;
    return A;
}
