//We can solve this problem by finding the position of mismatch. We start looping in the string by keeping two pointers at both the ends which traverse towards mid position after each iteration, this iteration will stop when we find a mismatch, as it is allowed to remove just one character we have two choices here,

//At mismatch, either remove character pointed by left pointer or remove character pointed by right pointer.

//We will check both the cases, remember as we have traversed equal number of steps from both sides, this mid string should also be a palindrome after removing one character, so we check two substrings, one by removing left character and one by removing right character and if one of them is palindrome then we can make complete string palindrome by removing corresponding character, and if both substrings are not palindrome then it is not possible to make complete string a palindrome under given constraint.

//Time Complexity - O(len(A))
//Space Complexity - O(1)
bool isPalindrome(string s){
    
    int l = 0, r = s.size() - 1;
    
    while(l < r){
        if(s[l] != s[r]){
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}
int Solution::solve(string A) {
    
    int l = 0, r = A.size() - 1;
    
    bool flag = true;
    
    while(l < r){
        
        if(A[l] != A[r]){
            flag = false;
            break;
        }
        l++;
        r--;
    }
    
    if(flag){
        return 1;
    }
    
    if(isPalindrome(A.substr(l,r-l)) || isPalindrome(A.substr(l+1,r-l))){
        return 1;
    }
    return 0;
}
