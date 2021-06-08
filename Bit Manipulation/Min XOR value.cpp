//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(1)
//Time Limit Exceeded
int Solution::findMinXor(vector<int> &A) {
    
    int n = A.size();
    int min_xor = INT_MAX;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            
            int val = A[i]^A[j];
            min_xor = min(min_xor,val);
        }
    }
    return min_xor;
}

//Method - 2
//Memory Limit Exceeded 
//Passed on LC
//Time Complexity - O(N)
//Ref: https://www.geeksforgeeks.org/minimum-xor-value-pair/
struct TrieNode{
    
    int val;
    TrieNode* left;
    TrieNode* right;
    
    TrieNode(){
        val = 0;
        left = NULL;
        right = NULL;
    }
};

void add(TrieNode* root, int n){
    
    for(int i = 31; i >= 0; i--){
        
        if((n & (1 << i)) != 0){
            if(root -> right == NULL){
                root -> right = new TrieNode();
            }
            root = root -> right;
        }
        else{
            if(root -> left == NULL){
                root -> left = new TrieNode();
            }
            root = root -> left;
        }
    }
    root -> val = n;
}

int findMinXOR(TrieNode* root, int n){
    
    for(int i = 31; i >= 0; i--){
        
        if((n & (1 << i)) != 0){
            
            if(root -> right != NULL){
                root = root -> right;
            }
            else{
                root = root -> left;
            }
        }
        else{
            
            if(root -> left != NULL){
                root = root -> left;
            }
            else{
                root = root -> right;
            }
        }
    }
    return (n ^ (root -> val));
}
int Solution::findMinXor(vector<int> &A) {
    
    TrieNode* root = new TrieNode();
    
    add(root,A[0]);
    
    int min_xor = INT_MAX;
    
    for(int i = 1; i < A.size(); i++){
        
        min_xor = min(min_xor, findMinXOR(root,A[i]));
        
        add(root,A[i]);
    }
    
    return min_xor;
}

//Method - 3
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=OZ2jghS0t24
int Solution::findMinXor(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int min_xor = INT_MAX;
    
    for(int i = 0; i < A.size() - 1; i++){
        min_xor = min(min_xor,A[i]^A[i+1]);
    }
    return min_xor;
}
