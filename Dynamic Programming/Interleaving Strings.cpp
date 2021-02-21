
    int check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3,unordered_map<string,int> &mem){
        
        if(p3 == len3){
            return (p1 == len1 && p2 == len2) ? 1 : 0;
        }
        
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        
        if(mem.find(key)!=mem.end()){
            return mem[key];
        }
        
        if(p1 == len1){
            if(s2[p2] == s3[p3]){
                return mem[key] = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mem);
            }
            else{
                return mem[key] = 0;
            }
        }
        if(p2 == len2){
            if(s1[p1] == s3[p3]){
                return mem[key] = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mem);
            }
            else{
                return mem[key] = 0;
            }
        }
        
        bool one = 0, two = 0;
        
        if(s1[p1] == s3[p3]){
            one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1,mem);
        }
        if(s2[p2] == s3[p3]){
            two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1,mem);
        }
        return mem[key] = one || two;
    }
int Solution::isInterleave(string A, string B, string C) {
    int len1 = A.length();
        int len2 = B.length();
        int len3 = C.length();
        
        if(len1 + len2 != len3){
            return 0;
        }
        unordered_map<string,int> mem;
        return check(A,B,C,len1,len2,len3,0,0,0,mem);
}
