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
