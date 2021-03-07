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
