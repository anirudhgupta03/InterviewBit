//Method - 1
//TLE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void merge(ListNode* &head, int l, int mid, int r){
    
    int n1 = mid - l + 1, n2 = r - mid;
    
    ListNode* temp = head,*start;
    
    int templ = l;
    
    while(l){
        temp = temp -> next;
        l--;
    }
    
    start = temp;
    
    ListNode* ptr1, *ptr2;
    
    ptr1 = new ListNode(temp->val);
    
    ListNode* temp1 = ptr1;
    temp = temp -> next;
    
    while(n1 != 1){
        temp1 -> next = new ListNode(temp -> val);
        temp1 = temp1 -> next;
        temp = temp -> next;
        n1--;
    }
    
    ptr2 = new ListNode(temp -> val);

    ListNode* temp2 = ptr2;
    temp = temp -> next;
    
    while(n2 != 1){
        temp2 -> next = new ListNode(temp -> val);
        temp2 = temp2 -> next;
        temp = temp -> next;
        n2--;
    }
    
    temp = start;
    
    while(ptr1 && ptr2){
        
        if(ptr1 -> val < ptr2 -> val){
            temp -> val = ptr1 -> val;
            ptr1 = ptr1 -> next;
            temp = temp -> next;
        }
        else{
            temp -> val = ptr2 -> val;
            ptr2 = ptr2 -> next;
            temp = temp -> next;
        }
    }
    
    while(ptr1){
        temp -> val = ptr1 -> val;
        ptr1 = ptr1 -> next;
        temp = temp -> next;
    }
    
    while(ptr2){
        temp -> val = ptr2 -> val;
        ptr2 = ptr2 -> next;
        temp = temp -> next;
    }
}
void mergesort(ListNode* &head, int l, int r){
    
    if(l >= r){
        return;
    }
        
    int mid = (l+r)/2;
        
    mergesort(head,l,mid);
    mergesort(head,mid+1,r);
    
    merge(head,l,mid,r);
}
ListNode* Solution::sortList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    int len = 0;
    
    ListNode* temp = A;
    
    while(temp){
        temp = temp -> next;
        len++;
    }
    
    mergesort(A,0,len - 1);
    
    return A;
}

//Method - 2
//Ref1: https://www.youtube.com/watch?v=KEoYzfOUF3o
//Ref2: https://www.youtube.com/watch?v=sGdwSH8RK-o
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* t1, ListNode* t2){
    
    ListNode* head;
    
    if(t1 -> val < t2 -> val){
        head = t1;
        t1 = t1 -> next;
    }
    else{
        head = t2;
        t2 = t2 -> next;
    }
    ListNode* prev = head;
    
    while(t1 && t2){
        if(t1 -> val < t2 -> val){
            prev -> next = t1;
            t1 = t1 -> next;
        }
        else{
            prev -> next = t2;
            t2 = t2 -> next;
        }
        prev = prev->next;
    }
    
    if(t1){
        prev-> next = t1;
    }
    if(t2){
        prev -> next = t2;
    }
    return head;
}
ListNode* Solution::sortList(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    
    ListNode* slow = A, *fast = A;
    
    ListNode* prev;
    
    while(fast != NULL && fast -> next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast->next->next;
    }
    prev -> next = NULL;
    return merge(sortList(A),sortList(slow));
}

//Method - 3
//Using Dummy Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* ptr = dummy;
    while(l1 && l2){
        if(l1 -> val < l2 -> val){
            ptr -> next = l1;
            ptr = l1;
            l1 = l1 -> next;
        }
        else{
            ptr -> next = l2;
            ptr = l2;
            l2 = l2 -> next;
        }
    }
    while(l1){
        ptr -> next = l1;
        ptr = l1;
        l1 = l1 -> next;
    }
    while(l2){
        ptr -> next = l2;
        ptr = l2;
        l2 = l2 -> next;
    }
    return dummy -> next;
}
ListNode* Solution::sortList(ListNode* A) {
    if(A == NULL || A -> next == NULL){
        return A;
    }
    ListNode* slow = A, *fast = A, *pre = NULL;
    while(slow && fast && fast -> next){
        pre = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    pre -> next = NULL;
    ListNode* l1 = sortList(A);
    ListNode* l2 = sortList(slow);
    return merge(l1, l2);
}
