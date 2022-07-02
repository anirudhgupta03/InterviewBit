//Method - 1
vector<int> Solution::stepnum(int A, int B) {
    
    map<int,vector<string>> m;
    
    for(int i = 1; i <= 9; i++){
        
        queue<string> q;
        q.push(to_string(i));
        
        while(1){
            
            string curr = q.front();
            q.pop();
            
            if(curr.size() == 9)
            break;
            
            m[i].push_back(curr);
            
            int last = curr[curr.size()-1] - 48;
            
            if(last == 0){
                curr.push_back('1');
                q.push(curr);
            }
            else if(last == 9){
                curr.push_back('8');
                q.push(curr);
            }
            else{
                string str1 = curr;
                string str2 = curr;
                
                str1.push_back(last+1+'0');
                str2.push_back(last-1+'0');
                
                q.push(str2);
                q.push(str1);
            }
        }
    }
    
    int count = 0;
    vector<int> res;
    
    if(A == 0){
        res.push_back(0);
    }
    
    for(int i = 1; i <= 9; i++){
        for(int j = 0; j < m[i].size(); j++){
            
            int x = stoi(m[i][j]);
            
            if(x>= A && x <= B){
                res.push_back(x);
            }
            else if(x > B){
                break;
            }
        }
    }
  
    sort(res.begin(),res.end());
    return res;
}

//Method - 2
vector<int> res;
void solve(int val, int A, int B){

    if(val > B){
        return;
    }
    if(val >= A && val <= B){
        res.push_back(val);
    }

    int last = val % 10;

    if(last != 0){
        solve(10*val + (last - 1), A, B);
    }
    if(last != 9){
        solve(10*val + (last + 1), A, B);
    }
}
vector<int> Solution::stepnum(int A, int B) {
    res.clear();
    for(int i = 1; i <= 9; i++){
        solve(i, A, B);
    }
    if(A == 0){
        res.push_back(0);
    }
    sort(res.begin(),res.end());
    return res;
}

//Method - 3
vector<int> Solution::stepnum(int A, int B) {
    
    queue<int> q;
    
    for(int i = 1; i <= 9; i++){
        q.push(i);
    }
    vector<int> res;
    if(A == 0) res.push_back(0);
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        
        if(curr > B){
            continue;
        }
        if(curr >= A && curr <= B){
            res.push_back(curr);
        }
        
        int lastdigit = curr % 10;
        if(lastdigit == 0){
            q.push(10*curr + 1);
        }
        else if(lastdigit == 9){
            q.push(10*curr + 8);
        }
        else{
            q.push(10*curr + lastdigit - 1);
            q.push(10*curr + lastdigit + 1);
        }
    }
    return res;
}
