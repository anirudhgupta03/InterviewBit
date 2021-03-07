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
