string Solution::findDigitsInBinary(int A) {
    
    string s;
    
    if(A == 0){
        return "0";
    }
    while(A != 0){
        string p;
        int rem = A%2;
        p = to_string(rem);
        A = A/2;
        s = s + p;
    }
    
    reverse(s.begin(),s.end());
    
    return s;
}
