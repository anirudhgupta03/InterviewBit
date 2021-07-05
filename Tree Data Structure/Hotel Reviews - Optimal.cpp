//Method - 1
struct TrieNode{
  
  int wordend;
  TrieNode* child[26];
  
  TrieNode(){
      wordend = 0;
      for(int i = 0; i < 26; i++){
          child[i] = NULL;
      }
  }
  
};

void add(string s, TrieNode* root, int idx){
    
    if(idx == s.size()){
        root -> wordend = 1;
        return;
    }
    
    if(root->child[s[idx]-'a'] == NULL){
        TrieNode* node = new TrieNode();
        root -> child[s[idx]-'a'] = node;
    }
    add(s,root->child[s[idx]-'a'],idx+1);
}

bool find(TrieNode* root,string s, int idx){
    
    if(root == NULL || idx == s.size() && root->wordend == 0){
        return false;
    }
    
    if(idx == s.size() && root->wordend == 1){
        return true;
    }
    
    return find(root->child[s[idx]-'a'],s,idx+1);
}

bool cmp(pair<pair<int,string>,int> p1, pair<pair<int,string>,int> p2){
    
    if(p1.second == p2.second){
        return p1.first.first < p2.first.first;
    }
    return p1.second > p2.second;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    
    int l = 0;
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '_'){
            add(A.substr(l,i-l),root,0);
            l = i + 1;
        }
    }
    add(A.substr(l,A.size()-l),root,0);
    
    vector<pair<pair<int,string>,int>> v;
    
    for(int i = 0; i < B.size(); i++){
        string C = B[i];
        int l = 0,count = 0;
        for(int j = 0; j < C.size(); j++){
            if(C[j] == '_'){
                if(find(root,C.substr(l,j-l),0)){
                    count++;
                }
                l = j + 1;
            }
        }
        if(find(root,C.substr(l,C.size()-l),0)){
            count++;
        }
        v.push_back({{i,C},count});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    vector<int> ans;
    for(int i = 0; i < v.size();i++){
        ans.push_back(v[i].first.first);
    }
    return ans;
}

//Method - 2
struct TrieNode{

    TrieNode* child[26];
    bool isLeaf;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        isLeaf = false;
    }
};
void add(TrieNode* root, string s){

    for(int i = 0; i < s.size(); i++){

        if(root -> child[s[i]-'a'] == NULL){
            root -> child[s[i]-'a'] = new TrieNode();
        }
        root = root -> child[s[i]-'a'];
    }

    root -> isLeaf = true;
}
bool find(TrieNode* root, string s){

    for(int i = 0; i < s.size(); i++){

        if(root -> child[s[i]-'a'] == NULL){
            return false;
        }
        root = root -> child[s[i]-'a'];
    }
    if(root->isLeaf == true){
        return true;
    }
    return false;
}
bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;

}
vector<int> Solution::solve(string A, vector<string> &B) {

    for(int i = 0; i < A.size(); i++){
        if(A[i] == '_'){
            A[i] = ' ';
        }
    }

    stringstream X(A);
    string temp;

    TrieNode* root = new TrieNode();

    while(X >> temp){
        add(root,temp);
    }
    vector<pair<int,int>> v;

    vector<int> res;

    for(int i = 0; i < B.size(); i++){

        int k = 0,count = 0;
        string temp = B[i];

        for(int j = 0; j < temp.size(); j++){
            
            if(temp[j] == '_'){
                if(find(root,temp.substr(k,j-k))){
                    count++;
                }
                k = j + 1;
            }
        }
        if(find(root,temp.substr(k,temp.size()-k))){
            count++;
        }
        v.push_back({count,i});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i = 0; i < v.size(); i++){
        res.push_back(v[i].second);
    }
    return res;
}
