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
