string Solution::findDigitsInBinary(int A) {
    if(A == 0) return "0";
    string res;
    while(A){
        res.push_back(A % 2 + '0');
        A >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}
