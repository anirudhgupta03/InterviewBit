//Method - 1
//TC - O(N)
//SC - O(1)
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    
    RandomListNode* temp1, *temp2, *temp3;

    temp1 = A;

    while(temp1 != NULL){
        temp2 = temp1;
        temp1 = temp1 -> next;
        temp3 = new RandomListNode(temp2 -> label);
        temp2 -> next = temp3;
        temp3 -> next = temp1;
    }
    
    
    temp1 = A;
    while(temp1 != NULL){
        temp2 = temp1 -> next;
        if(temp1 -> random != NULL){
            temp2 -> random = temp1 -> random -> next;
        }
        temp1 = temp2 -> next;
    }
    
    RandomListNode* head, *prev = NULL;

    temp1 = A, temp2 = A -> next;

    while(temp1){
        temp1 -> next = temp2 -> next;
        temp1 = temp2 -> next;
        if(prev == NULL){
            head = temp2;
        }
        prev = temp2;
        if(temp1 != NULL){
            temp2 -> next = temp1 -> next;
            temp2 = temp1 -> next;
        }
    }

    return head;
}

//Method - 2
//TC - O(N)
//SC - O(N)
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {

    unordered_map<RandomListNode*, RandomListNode*> umap;

    RandomListNode* temp = A;

    while(temp){
        RandomListNode* node = new RandomListNode(temp -> label);
        node -> next = temp -> next;
        temp -> next = node;
        umap[temp] = node;
        temp = node -> next;
    }

    temp = A;
    while(temp){
        temp -> next -> random = umap[temp -> random];
        temp = temp -> next -> next;
    }

    RandomListNode* root = A -> next;
    temp = A -> next;
    while(temp -> next){
        temp -> next = temp -> next -> next;
        temp = temp -> next;
    }
    return root;
}

//Method - 3
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    if(A == NULL){
        return NULL;
    }
    
    RandomListNode* B = A;
    
    while(B){
        RandomListNode* newNode = new RandomListNode(B -> label);
        RandomListNode* nextNode = B -> next;
        B -> next = newNode;
        newNode -> next = nextNode;
        B = nextNode;
    }
    
    B = A;
    while(B){
        RandomListNode* nextNode = B -> next;
        RandomListNode* randomNode = B -> random;
        
        if(randomNode != NULL){
            nextNode -> random = randomNode -> next;
        }
        B = nextNode -> next;
    }
    
    B = A -> next;
    while(B -> next){
        B -> next = B -> next -> next;
        B = B -> next;
    }
    return A -> next;
}
