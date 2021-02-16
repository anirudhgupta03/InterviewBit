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
