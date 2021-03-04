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
