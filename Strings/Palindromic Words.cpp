bool isPalindrome(string &s){

    int lo = 0, hi = s.size() - 1;
    while(lo < hi){
        if(s[lo] != s[hi]){
            return false;
        }
        lo++;
        hi--;
    }
    return true;
}
int Solution::solve(string A) {

    int count = 0;
    string s;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == ' '){
            if(isPalindrome(s)){
                count++;
            }
            s = "";
        }
        else{
            s.push_back(A[i]);
        }
    }
    if(isPalindrome(s)){
        count++;
    }
    return count;
}
