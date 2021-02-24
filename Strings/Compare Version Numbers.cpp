int Solution::compareVersion(string A, string B) {
    
    int i = 0, j = 0;
    
    int n1 = A.size(), n2 = B.size();
    
    while(i < n1 || j < n2)
    {
        string s1, s2;
        
        while(A[i] != '.' && i < n1){
            
            if(s1.size() == 0 && A[i] == '0'){
                i++;
                continue;
            }
            s1 += A[i];
            i++;
        }
        i++;
        while(B[j] != '.' && j < B.size()){
            
            if(s2.size() == 0 && B[j] == '0'){
                j++;
                continue;
            }
            s2 += B[j];
            j++;
        }
        j++;
        if(s1.size() > s2.size()){
            return 1;
        }
        else if(s1.size() < s2.size()){
            return -1;
        }
        else{
            if(s1>s2) return 1;
            else if(s1<s2) return -1;
        }
    }
    return 0;
}
