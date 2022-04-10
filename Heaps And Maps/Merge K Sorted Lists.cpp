//Method - 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* l1, ListNode* l2){
    
    if(l1 == NULL && l2 == NULL){
        return NULL;
    }
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    
    ListNode* prev = NULL, *head;
    
    while(l1 && l2){
        
        if(l1 -> val < l2 -> val){
            if(prev == NULL){
                head = l1;
            }
            else{
                prev -> next = l1;
            }
            prev = l1;
            l1 = l1 -> next;
        }
        else{
            if(prev == NULL){
                head = l2;
            }
            else{
                prev -> next = l2;
            }
            prev = l2;
            l2 = l2 -> next;
        }
    }
    
    if(l1){
        prev -> next = l1;
    }
    if(l2){
        prev -> next = l2;
    }
    
    return head;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    ListNode* head = A[0];
    
    for(int i = 1; i < A.size(); i++){
        head = merge(head,A[i]);
    }
    return head;
}

//Method - 2
//Optimal
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Same Approach as used in Merge K Sorted Arrays

#define pili pair<int,pair<ListNode*,int>>
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    priority_queue<pili,vector<pili>,greater<pili>> pq;
    
    int n = A.size();
    
    for(int i = 0; i < n; i++){
        pq.push({A[i]->val,{A[i],i}});
    }
    
    ListNode* temp = NULL;
    ListNode* root;

    while(!pq.empty()){
        
        if(temp == NULL){
            temp = pq.top().second.first;
            root = temp;
        }
        else{
            temp -> next = pq.top().second.first;
            temp = temp -> next;
        }
        
        int ind = pq.top().second.second;
        pq.pop();
        
        if(A[ind] -> next != NULL){
            A[ind] = A[ind] -> next;
            pq.push({A[ind]->val,{A[ind],ind}});
        }  
    }
    return root;
}

//Method - 3
//Best
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(ListNode* &list1, ListNode* &list2){
        return list1 -> val > list2 -> val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

    for(int i = 0; i < A.size(); i++){
        pq.push(A[i]);
    }

    ListNode* root = NULL, *pre = NULL;

    while(!pq.empty()){
        ListNode* curr = pq.top();
        pq.pop();

        if(root == NULL) root = curr;
        else pre -> next = curr;
        pre = curr;

        if(curr -> next){
            pq.push(curr -> next);
        }
    }
    return root;
}
