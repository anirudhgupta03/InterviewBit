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

//Alter
//Ref: https://www.youtube.com/watch?v=mIZJIuMpI2M
int isValid(string &s1, string &s2){
    int count = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]){
            count++;
        }
    }
    return count == 1 ? 1 : 0;
}
void dfs(int depth, int curr, int end, vector<string> &temp, vector<vector<string>> &res, vector<int> al[], vector<int> &vis, vector<string> &dict){

    if(depth == 0 && curr == end){
        res.push_back(temp);
        return;
    }
    if(depth == 0 || curr == end){
        return;
    }

    for(int i = 0; i < al[curr].size(); i++){
        int child = al[curr][i];
        if(vis[child] == 0){
            vis[child] = 1;
            temp.push_back(dict[child]);
            dfs(depth - 1, child, end, temp, res, al, vis, dict);
            vis[child] = 0;
            temp.pop_back();
        }
    }
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    
    unordered_set<string> valid;

    for(string &s: dict){
        valid.insert(s);
    }
    valid.insert(start);
    valid.insert(end);

    dict.clear();

    for(string s: valid){
        dict.push_back(s);
    }

    int n = dict.size();
    vector<int> al[n];

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(isValid(dict[i], dict[j])){
                al[i].push_back(j);
                al[j].push_back(i);
            }
        }
    }

    int sind, eind;
    for(int i = 0; i < n; i++){
        if(dict[i] == start) sind = i;
        if(dict[i] == end) eind = i;
    }

    queue<int> q;
    int steps = 0;
    q.push(sind);

    vector<int> vis(n, 0);
    
    //BFS to find the depth
    bool flag = false;
    while(!q.empty()){
        int sz = q.size();
        steps++;
        while(sz--){
            int currind = q.front();
            q.pop();

            if(currind == eind){
                flag = true;
                break;
            }
            if(vis[currind]) continue;
            vis[currind] = 1;

            for(int i = 0; i < al[currind].size(); i++){
                int child = al[currind][i];
                if(vis[child] == 0){
                    q.push(child);
                }
            } 
        }
        if(flag){
            break;
        }
    }

    vector<vector<string>> res;
    if(!flag){
        return res;
    }
    vector<string> temp;
    temp.push_back(start);

    for(int i = 0; i < n; i++) vis[i] = 0;
    vis[sind] = 1;
     
    //DFS
    dfs(steps - 1, sind, eind, temp, res, al, vis, dict);

    return res;
}
