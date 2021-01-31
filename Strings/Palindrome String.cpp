int Solution::isPalindrome(string A) {
    
    string p;
    for(int i = 0; i < A.size(); i++){
        
        if(isupper(A[i])){
            p += char(A[i] + 32); //a=a+b will concatenate the strings and copy the entire string into a again. while a+=b will simply concatenate b after a (not copying again)
        }
        else if(isalpha(A[i]) || isdigit(A[i])){
            p += A[i];
        }
    }
    int l = 0, r= p.size()-1;
    
    while(l<r){
        
        if(p[l] != p[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}
