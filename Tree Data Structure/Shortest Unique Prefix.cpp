//Ref: https://www.youtube.com/watch?v=fpjfjNh658c
//Method - 1
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

//Method - 2
struct TrieNode{

    int count;
    TrieNode* child[26];

    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        count = 0;
    }
};
void add(TrieNode* root, string s){

    for(int i = 0; i < s.size(); i++){

        if(root -> child[s[i]-'a'] == NULL){
            root -> child[s[i]-'a'] = new TrieNode();
        }
        root = root -> child[s[i]-'a'];
        root -> count++;
    }
    root -> count++;
}
string findSUP(TrieNode* root, string s){

    string temp;

    for(int i = 0; i < s.size(); i++){

        if(root -> child[s[i]-'a'] -> count != 1){
            temp.push_back(s[i]);
        }
        else{
            temp.push_back(s[i]);
            break;
        }
        root = root -> child[s[i]-'a'];
    }
    return temp;
}
vector<string> Solution::prefix(vector<string> &A) {

    vector<string> res;

    TrieNode* root = new TrieNode();

    for(int i = 0; i < A.size(); i++){
        add(root,A[i]);
    }

    for(int i = 0; i < A.size(); i++){
        res.push_back(findSUP(root,A[i]));
    }

    return res;
}
