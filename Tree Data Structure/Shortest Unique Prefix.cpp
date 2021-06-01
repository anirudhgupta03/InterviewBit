//Ref: https://www.youtube.com/watch?v=fpjfjNh658c
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

void add(TrieNode* root, string s, int idx){
    
    if(idx == s.size()){
        return;
    }
    
    if(root->child[s[idx]-'a'] == NULL){
        root->child[s[idx]-'a'] = new TrieNode();
    }
    root->child[s[idx]-'a']->freq++;
    add(root->child[s[idx]-'a'],s,idx+1);
}

int find(TrieNode* root, string s, int idx){
    
    if(root->child[s[idx]-'a']->freq == 1){
        return idx;
    }
    if(root->child[s[idx]-'a'] != NULL){
        return find(root->child[s[idx]-'a'],s,idx+1);
    }
}
vector<string> Solution::prefix(vector<string> &A) {
    
    int n = A.size();
    vector<string> ans;
    
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < n; i++){
        add(root,A[i],0);
    }
    
    for(int i = 0; i < n; i++){
        
        int idx = find(root,A[i],0);
        string s = A[i].substr(0,idx+1);
        ans.push_back(s);
    }
    return ans;
}
