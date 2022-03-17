int Solution::solve(string A, string B, vector<string> &C) {

    unordered_set<string> us;

    for(int i = 0; i < C.size(); i++){
        us.insert(C[i]);
    }

    queue<string> q;
    q.push(A);

    unordered_map<string,int> dist;
    dist[A] = 1;

    while(!q.empty()){

        string curr = q.front();
        q.pop();

        for(int i = 0; i < curr.size(); i++){
            string temp = curr;
            for(char c = 'a'; c <= 'z'; c++){
                temp[i] = c;
                if(curr == temp) continue;
                if(temp == B) return dist[curr] + 1;
                if(us.find(temp) != us.end()){
                    q.push(temp);
                    dist[temp] = dist[curr] + 1;
                    us.erase(temp);
                }
            }
        }
    }
    return 0;
}

//Alter
int Solution::solve(string A, string B, vector<string> &C) {
    if(A == B){
        return 0;
    }
    unordered_set<string> valid, vis;
    for(int i = 0; i < C.size(); i++){
        valid.insert(C[i]);
    }
    valid.insert(B);
    queue<string> q;
    q.push(A);
    int steps = 1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            string curr = q.front();
            q.pop();
            if(curr == B){
                return steps;
            }
            if(vis.find(curr) != vis.end()) continue;
            vis.insert(curr);
            for(int i = 0; i < curr.size(); i++){
                char ch = curr[i];
                for(int j = 0; j < 26; j++){
                    curr[i] = (j + 'a');
                    if(valid.find(curr) != valid.end() && vis.find(curr) == vis.end()){
                        q.push(curr);
                    }
                }
                curr[i] = ch;
            }
        }
        steps++;
    }
    return 0;
}
