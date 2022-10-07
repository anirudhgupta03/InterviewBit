//Method - 1
//Ref: https://www.youtube.com/watch?v=jCu-Pd0IjIA&t=110s
struct TrieNode{
  
  TrieNode* left;
  TrieNode* right;
  
  TrieNode(){
      left = NULL;
      right = NULL;
  }
  
};

void add(int n, TrieNode* root){
    
    for(int i = 31; i >= 0; i--){
        
        int bit = (n>>i)&1;
        
        if(bit == 0){
            if(root -> left == NULL){
                root -> left = new TrieNode();
            }
            root = root->left;
        }
        else{
            if(root -> right == NULL){
                root -> right = new TrieNode();
            }
            root = root->right;
        }
    }
}

int findMaxXOR(TrieNode* root, int n){
    
    int sum = 0;
    
    for(int i = 31; i >= 0; i--){
        
        int bit = (n>>i)&1;
        if(bit == 0){
            if(root -> right != NULL){
                sum += pow(2,i);
                root = root -> right;
            }
            else{
                root = root -> left;
            }
        }
        else{
            if(root -> left != NULL){
                sum += pow(2,i);
                root = root -> left;
            }
            else{
                root = root -> right;
            }
        }
    }
    return sum;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < A.size(); i++){
        add(A[i],root);
    }
    
    int max_XOR = 0;
    
    for(int i = 0; i < B.size(); i++){
        max_XOR = max(max_XOR,findMaxXOR(root,B[i]));
    }
    
    return max_XOR;
}

//Method - 2
struct TrieNode{

    TrieNode* child[2];
    TrieNode(){
        for(int i = 0; i < 2; i++){
            child[i] = NULL;
        }
    }
};
void add(TrieNode* root, int num){

    for(int i = 31; i >= 0; i--){
        
        int bit = (num & (1 << i)) ? 1 : 0;
        if(root -> child[bit] == NULL){
            root -> child[bit] = new TrieNode();
        }
        root = root -> child[bit];
    }
}
int findMaxXOR(TrieNode* root, int num){

    int xorsum = 0;

    for(int i = 31; i >= 0; i--){
        
        int bit = (num & (1 << i)) ? 1 : 0;

        if(root -> child[1-bit] != NULL){
            root = root -> child[1-bit];
            xorsum += pow(2,i);
        }
        else{
            root = root -> child[bit];
        }
    }
    return xorsum;
}
int Solution::solve(vector<int> &A, vector<int> &B) {

    TrieNode* root = new TrieNode();

    for(int i = 0; i < A.size(); i++){
        add(root,A[i]);
    }
    int maxXOR = 0;
    for(int i = 0; i < B.size(); i++){
        maxXOR = max(maxXOR,findMaxXOR(root,B[i]));
    }

    return maxXOR;
}

//Alter
struct TrieNode{
    TrieNode* child[2];
    TrieNode(){
        for(int i = 0; i < 2; i++){
            child[i] = NULL;
        }
    }
};
void insert(TrieNode* root, vector<int> &bits){

    for(int i = 0; i < 32; i++){
        if(root -> child[bits[i]] == NULL){
            root -> child[bits[i]] = new TrieNode();
        }
        root = root -> child[bits[i]];
    }
}
int findMaxXOR(int num, TrieNode* root){

    vector<int> bits(32, 0);
    for(int j = 31; j >= 0; j--){
        bits[j] = num % 2;
        num /= 2;
    }

    int XORSum = 0;
    for(int i = 0; i <= 31; i++){
        if(root -> child[1 - bits[i]]){
            XORSum += (1 << (31 - i));
            root = root -> child[1 - bits[i]];
        }
        else{
            root = root -> child[bits[i]];
        }
    }
    return XORSum;
}
int Solution::solve(vector<int> &A, vector<int> &B) {

    TrieNode* root = new TrieNode();

    for(int i = 0; i < A.size(); i++){
        vector<int> bits(32, 0);
        int num = A[i];
        for(int j = 31; j >= 0; j--){
            bits[j] = num % 2;
            num /= 2;
        }
        insert(root, bits);
    }

    int maxXOR = 0;

    for(int i = 0; i < B.size(); i++){
        maxXOR = max(maxXOR, findMaxXOR(B[i], root));
    }
    return maxXOR;
}

//Neat and Clean Code
struct TrieNode{
    TrieNode* child[2];
    TrieNode(){
        child[0] = child[1] = NULL;
    }  
};
void insert(TrieNode* root, int val){
    for(int i = 31; i >= 0; i--){
        int bit = (val & (1 << i)) == 0 ? 0 : 1;
        if(root -> child[bit] == NULL){
            root -> child[bit] = new TrieNode();
        }
        root = root -> child[bit];
    }   
}
int findMaxXOR(TrieNode* root, int val){
    
    int maxXOR = 0;
    for(int i = 31; i >= 0; i--){
        int bit = (val & (1 << i)) == 0 ? 0 : 1;
        if(root -> child[1 - bit]){
            maxXOR |= (1 << i);
            root = root -> child[1 - bit];
        }
        else{
            root = root -> child[bit];
        }
    }   
    return maxXOR;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < A.size(); i++){
        insert(root, A[i]);
    }
    
    int maxXOR = 0;
    for(int i = 0; i < B.size(); i++){
        maxXOR = max(maxXOR, findMaxXOR(root, B[i]));
    }
    return maxXOR;
}
