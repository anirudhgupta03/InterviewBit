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
