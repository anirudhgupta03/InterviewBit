vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    
    int len = B[0].size();
    int size = B.size();
    
    vector<int> res;
    unordered_map<string,int> given_words;
    
    if(len*size > A.size()){
        return res;
    }
    
    for(int i = 0; i < size; i++){
        given_words[B[i]]++;
    }
    
    for(int i = 0; i < A.size() - (len*size) + 1; i++){
        
        unordered_map<string,int> used_words;
        
        for(int j = i; j < i + len*size; j += len){
            
            string curr = A.substr(j,len);
            
            if(given_words.find(curr) == given_words.end()){
                break;
            }
            
            used_words[curr]++;
            
            if(used_words[curr] > given_words[curr]){
                break;
            }
        }
        
        if(given_words == used_words){
            res.push_back(i);
        }
    }
    return res;
}
