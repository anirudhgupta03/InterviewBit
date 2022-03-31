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
//TLE
string Solution::multiple(int A) {

    if(A == 1){
        return "1";
    }
    queue<int> q;
    q.push(1);
    
    vector<string> v(A);    //r = 0 to A - 1
    v[1] = "1";

    while(!q.empty()){
        int r = q.front();
        q.pop();

        if(r == 0){
            break;
        }

        int r0 = (r*10)%A;
        int r1 = (r*10 + 1)%A;
        if(v[r0].size() == 0){
            v[r0] = v[r] + "0";
            q.push(r0);
        }
        if(v[r1].size() == 0){
            v[r1] = v[r] + "1";
            q.push(r1);
        }
    }
    return v[0];
}

//Method - 3
string Solution::multiple(int A) {

    if(A == 1){
        return "1";
    }
    queue<int> q;
    q.push(1);
    
    vector<char> v(A, '2');    //r = 0 to A - 1
    v[1] = '1';
    vector<int> par(A);
    par[1] = -1;
    
    while(!q.empty()){
        int r = q.front();
        q.pop();
        if(r == 0){
            break;
        }
        int r0 = (r*10)%A;
        int r1 = (r*10 + 1)%A;
        if(v[r0] == '2'){
            v[r0] = '0';
            par[r0] = r;
            q.push(r0);
        }
        if(v[r1] == '2'){
            v[r1] = '1';
            par[r1] = r;
            q.push(r1);
        }
    }
    string res;
    int rem = 0;
    while(rem != 1){
        res.push_back(v[rem]);
        rem = par[rem];
    }
    res.push_back('1');
    reverse(res.begin(),res.end());
    return res;
}
