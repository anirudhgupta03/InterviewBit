//Method - 1
string Solution::countAndSay(int A) {
    
    string s = "1";
    
    if(A == 1){
        return s;
    }
    for(int i = 2; i <= A; i++){
        
        int j = 0;
        string temp = s;
        s.clear();
        
        while(j < temp.size()){
            int count = 0;
            char p;
            p = temp[j];
            while(j < temp.size() && temp[j] == p){
                count++;
                j++;
            }
            s += to_string(count) + p;
        }
    }
    return s;
}

//Method - 2
//Using Two Pointer 
string Solution::countAndSay(int A) {
    
    if(A == 0){
        return "";
    }
    string prev = "1";
    
    for(int i = 1; i < A; i++){
        
        int n = prev.size(), l = 0, r = 0, count = 0;
        
        string res;
        
        while(r < n){
            
            if(prev[r] == prev[l]){
                count++;
                r++;
            }
            else{
                res.push_back(count+'0');
                res.push_back(prev[l]);
                l = r;
                count = 0;
            }
        }
        res.push_back(count+'0');
        res.push_back(prev[l]);
        prev = res;
    }
    return prev;
}

//Method - 3
string Solution::countAndSay(int A) {
    string pre = "1";
    A--;
    while(A--){
        string curr;
        char ele;
        int i = 0, count;
        while(i < pre.size()){
            count = 0;
            ele = pre[i];
            while(i < pre.size() && pre[i] == ele){
                count++;
                i++;
            }
            curr += to_string(count);
            curr.push_back(ele);
        }
        pre = curr;
    }
    return pre;
}
