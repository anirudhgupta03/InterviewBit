bool isPalindrome(int n){
    string s = to_string(n);
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
int Solution::solve(int A, int B, int C) {
    vector<int> palindromes;
    
    for(int i = A; i <= B; i++){
        if(isPalindrome(i)){
            palindromes.push_back(i);
        }
    }
    int lo = 0, hi = 0, maxLen = 0;

    while(hi < palindromes.size()){
        while(lo < hi && palindromes[hi] - palindromes[lo] > C){
            lo++;
        }
        hi++;
        maxLen = max(maxLen, hi - lo);
    }
    return maxLen;
}
