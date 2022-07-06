//Method - 1
int Solution::solve(ListNode* A, int B) {
    
    int n = 0;
    
    ListNode* temp = A;
    
    while(temp != NULL)
    {
        n++;
        temp = temp -> next;
    }
    
    int l = (n/2 + 1 - B); //Position from left
    
    if(l <= 0){
        return -1;
    }
    
    int count = 1;
    temp = A;
    
    while(count != l)
    {
        temp = temp -> next;
        count++;
    }
    
    return temp-> val;
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
int Solution::solve(ListNode* A, int B) {
    
    ListNode* slow = A, *fast = A, *pre = NULL;
    int dist = 0;
    
    while(fast && fast -> next){
        pre = slow;
        slow = slow -> next;
        dist++;
        fast = fast -> next -> next;
    }
    dist -= B;
    if(dist < 0){
        return -1;
    }
    while(dist){
        A = A -> next;
        dist--;
    }
    return A -> val;
}
