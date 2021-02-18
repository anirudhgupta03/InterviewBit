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
