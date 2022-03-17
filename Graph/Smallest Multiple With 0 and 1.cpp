//Ref: https://www.youtube.com/watch?v=Om47LiGTy8o
//Method - 1
//TLE
int mod(string s, int A){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        curr = curr*10 + (s[i] - '0');
        curr %= A;
    }
    return curr;
}
string Solution::multiple(int A) {

    queue<string> q;
    q.push("1");

    unordered_set<string> vis;

    while(!q.empty()){
        string s = q.front();
        q.pop();
        int r = mod(s, A);
        if(r == 0){
            return s;
        }
        if(vis.find(s) != vis.end()) continue;
        vis.insert(s);
        q.push(s + "0");
        q.push(s + "1");
    }
}

//Method - 2
