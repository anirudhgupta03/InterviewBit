//Ref1: https://www.youtube.com/watch?v=3COJ95juomM
//Ref2: https://www.youtube.com/watch?v=pBYTiYyckGA
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
void add1(string &s){
    int carry = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        int curr = s[i] - '0' + carry;
        s[i] = curr % 10 + '0';
        carry = curr/10;
        if(carry == 0) break;
    }
    if(carry) s.insert(s.begin(), carry + '0');
}
string Solution::solve(string A) {

    if(isPalindrome(A)) add1(A);

    int len = A.size();

    
    if(len % 2 != 0){
        string left = A.substr(0, len/2);  
        string mid;
        mid.push_back(A[len/2]);
        string right =  A.substr(len/2 + 1);

        string revleft = left;
        reverse(revleft.begin(), revleft.end());

        if(revleft > right){
            return left + mid + revleft;
        }
        else{
            left = left + mid;
            add1(left);
            revleft = left;
            revleft.pop_back();
            reverse(revleft.begin(), revleft.end());
            return left + revleft;
        }
    }
    else{
        string left = A.substr(0, len/2);
        string right = A.substr(len/2);

        string revleft = left;
        reverse(revleft.begin(), revleft.end());

        if(revleft > right){
            return left + revleft;
        }
        else{
            add1(left);
            revleft = left;
            reverse(revleft.begin(), revleft.end());
            return left + revleft;
        }
    }
}
