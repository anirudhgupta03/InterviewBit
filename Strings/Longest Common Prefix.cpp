//Method - 1
//Time Complexity - O(N*min_len)
//Space Complexity - O(1)
string Solution::longestCommonPrefix(vector<string> &A) {
    
    int n = A.size();
    
    int min_len = INT_MAX;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i].size() < min_len){
            min_len = A[i].size();
        }
    }
    
    string res;
    
    for(int i = 0; i < min_len; i++){
        
        char curr = A[0][i];
        
        for(int j = 1; j < n; j++){
            if(curr != A[j][i]){
                return res;
            }
        }
        res.push_back(curr);
    }
    return res;
}
//Method - 2
//Time Complexity - O(L*NlogN)
//Ref: https://stackoverflow.com/questions/34318489/is-it-true-that-sorting-strings-is-on2logn/34318565
//Space Complexity - O(1)
string Solution::longestCommonPrefix(vector<string> &A) {
    
    sort(A.begin(),A.end());
    
    int i = 0;
    
    string ans;
    
    while(A[0][i] == A[A.size()-1][i] && i < min(A[0].size(),A[A.size()-1].size())){
        ans += A[0][i];
        i++;
    }
    
    return ans;
}
//Method - 3
//Using Trie
//Memory Limit Exceeded passed on LC
struct TrieNode{
    
    int pc;
    TrieNode* child[26];
    
    TrieNode(){
        pc = 0;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};
 
void add(string s, TrieNode* root, int idx){
    
    if(idx == s.size()){
        return;
    }
    
    if(root -> child[s[idx]-'a'] == NULL){
        root->child[s[idx]-'a'] = new TrieNode();
    }
    
    root->child[s[idx]-'a']->pc++;
    add(s,root->child[s[idx]-'a'],idx+1);
}
 
int findLCP(TrieNode* root, string s, int idx, int n){
    
    if(idx == s.size() || root->child[s[idx]-'a']->pc < n){
        return idx;
    }
    
    if(root->child[s[idx]-'a'] != NULL){
        return findLCP(root->child[s[idx]-'a'],s,idx+1,n);
    }
}
string Solution::longestCommonPrefix(vector<string> &A) {
    
    int n = A.size();
    
    if(n == 1){
        return A[0];
    }
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < A.size(); i++){
        add(A[i],root,0);
    }
    int ans = 0;
    return A[0].substr(0,findLCP(root,A[0],0,n));
}

//Method - 4
//Using Trie
struct TrieNode{
    int freq;
    TrieNode* child[26];
    TrieNode(){
        freq = 0;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }  
};
void insert(TrieNode* root, string &s){
    
    for(int i = 0; i < s.size(); i++){
        if(root -> child[s[i] - 'a'] == NULL){
            root -> child[s[i] - 'a'] = new TrieNode();
        }
        root = root -> child[s[i] - 'a'];
        root -> freq++;
    }
}
string searchLCP(TrieNode* root, string &s, int n){
    
    string lcp;
    for(int i = 0; i < s.size(); i++){
        if(root -> child[s[i] - 'a'] == NULL){
            return lcp;
        }
        root = root -> child[s[i] - 'a'];
        if(root -> freq == n){
            lcp.push_back(s[i]);
        }
        else{
            return lcp;
        }
    }
    return lcp;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    
    TrieNode* root = new TrieNode();
    for(int i = 0; i < A.size(); i++){
        insert(root, A[i]);
    }
    return searchLCP(root, A[0], A.size());
}
