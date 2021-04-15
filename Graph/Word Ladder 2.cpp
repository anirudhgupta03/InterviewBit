//BFS+DFS
bool isValid(string p, string q){
        
        int count = 0;
        
        for(int i = 0; i < p.size(); i++){
            
            if(p[i] != q[i]){
                count++;
            }
        }
        if(count == 1){
            return true;
        }
        return false;
}
void dfs(int s, int e, vector<vector<string>> &ans, vector<int> spal[], vector<int> &path, vector<string> &wordList){
        
        if(s == e){
            vector<string> v;
            for(int i = 0; i < path.size(); i++){
                v.push_back(wordList[path[i]]);
            }
            ans.push_back(v);
            //path.pop_back();
            return;
        }
        
        for(int i = 0; i < spal[s].size(); i++){
            path.push_back(spal[s][i]);
            dfs(spal[s][i], e, ans, spal, path, wordList);
            path.pop_back();
        }
        
        //return;
}
vector<vector<string> > Solution::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    
        vector<vector<string>> ans;
        
        int s,e;
        
        set<string> dict;
        
        for(int i = 0; i < wordList.size(); i++){
            dict.insert(wordList[i]);
        }
        if(dict.find(endWord) == dict.end()){
            dict.insert(endWord);
        }
        
        if(dict.find(beginWord) == dict.end()){
            dict.insert(beginWord);
        }
        
        wordList.clear();
        
        set<string> :: iterator it;
        
        for(it = dict.begin(); it != dict.end(); it++){
            
            wordList.push_back(*it);
        }
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == beginWord) s = i;
            if(wordList[i] == endWord) e = i;
        }
        int n = wordList.size();
        
        vector<int> al[n];
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                string p = wordList[i];
                string q = wordList[j];
                
                if(isValid(p,q)){
                    al[i].push_back(j);
                    al[j].push_back(i);
                }
            }
        }
        
        vector<int> spal[n];
        
        vector<int> depth(n,-1);
        depth[s] = 0;
        
        queue<int> q;
        q.push(s);
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(int i = 0; i < al[curr].size(); i++){
                
                int child = al[curr][i];
                
                if(depth[child] == -1){
                    depth[child] = depth[curr] + 1;
                    q.push(child);
                    spal[curr].push_back(child);
                }
                else if(depth[child] == depth[curr] + 1){
                    spal[curr].push_back(child);
                }
            }
        }
        vector<int> path;
        path.push_back(s);
        dfs(s,e,ans,spal,path,wordList);
        
        return ans;
}
