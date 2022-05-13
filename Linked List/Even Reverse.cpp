//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    
    int size = 0;
    
    ListNode *temp = A, *prev;
    
    while(temp != NULL){
        temp = temp -> next;
        size++;
    }
    if(size <= 3){
        return A;
    }
    
    int count = 0;
    temp = A;
    
    while(count != size/2){
        prev = temp;
        temp = temp -> next;
        count++;
    }
    prev -> next = NULL;
    ListNode *temp1 = NULL, *temp2 = temp, *temp3 = temp -> next;
    
    while(temp3 != NULL){                     //Reverse the latter half of the linked list
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    temp2 -> next = temp1;
    
    ListNode *ptr1 = A->next, *ptr2;
    if(size % 2 == 0){                         //If the complete linked list is of even size then the first position of the reversed linked list will be an even position
        ptr2 = temp2;
    }
    else{
        ptr2 = temp2 -> next;                  //If the complete linked list is of odd size then the second position of the reversed linked list will be an even position
    }
    
    while(ptr1 && ptr2){                       //Using two pointers swap the values at even positions
        swap(ptr1 -> val,ptr2 -> val);
        if(ptr1 -> next != NULL)ptr1 = ptr1 -> next -> next;
        if(ptr2 -> next != NULL)ptr2 = ptr2 -> next -> next;
    }
    
    temp1 = NULL, temp3 = temp2 -> next;
    while(temp3!=NULL){                        //Again reverse the later half of the linked list 
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    temp2 -> next = temp1;                     
    prev -> next = temp2;                      //Merge both the halves
    return A;
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
ListNode* reverse(ListNode* list){
    if(list == NULL || list -> next == NULL){
        return list;
    }
    ListNode* temp1 = NULL, *temp2 = list, *temp3 = list -> next;
    while(temp3){
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
    }
    temp2 -> next = temp1;
    return temp2;
}
ListNode* Solution::solve(ListNode* A) {

    if(A == NULL || A -> next == NULL){
        return A;
    }
    ListNode* temp = A;
    int len = 0;

    while(temp){
        len++;
        temp = temp -> next;
    }

    ListNode* pre = NULL, *slow = A, *fast = A;

    while(fast && fast -> next){        
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    pre -> next = NULL;                         //Divide the linked list from the middle
    slow = reverse(slow);                       //Reverse the second half

    ListNode* temp1 = A, *temp2 = slow;
    ListNode* pre1 = temp1, *pre2 = NULL;
    temp1 = temp1 -> next;

    if(len % 2 != 0){
        pre2 = temp2;
        temp2 = temp2 -> next;
    }
    
    ListNode* t1, *t2;
    while(temp1 && temp2){                      //Swapping the nodes
        
        t1 = temp1 -> next;
        t2 = temp2 -> next;
        pre1 -> next = temp2;
        temp2 -> next = t1;
        pre1 = t1;

        if(pre2 == NULL){
            slow = temp1;
        }
        else{
            pre2 -> next = temp1;
        }
        temp1 -> next = t2;
        pre2 = t2;

        if(t1) temp1 = t1 -> next;
        else break;
        
        if(t2) temp2 = t2 -> next;
        else break;
    }
    slow = reverse(slow);                      //Again reverse the latter half of the linked list
    pre = NULL, temp = A;

    while(temp){
        pre = temp;
        temp = temp -> next;
    }
    pre -> next = slow;
    return A;
}
