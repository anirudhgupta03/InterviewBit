//Method - 1
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

//Method - 2
int Solution::isPalindrome(string A) {

    int lo = 0, hi = A.size() - 1;

    while(lo < hi){
        
        while(lo < hi && !(isalpha(A[lo]) || A[lo] >= '0' && A[lo] <= '9')) lo++;
        while(lo < hi && !(isalpha(A[hi]) || A[hi] >= '0' && A[hi] <= '9')) hi--;

        if(isalpha(A[lo]) && isalpha(A[hi])){
            if(tolower(A[lo]) != tolower(A[hi])){
                return 0;
            }
        }
        else if(A[lo] != A[hi]){
            return 0;
        }
        lo++;
        hi--;
    }
    return 1;
}
