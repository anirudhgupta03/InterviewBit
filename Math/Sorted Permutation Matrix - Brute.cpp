int fact(int n){
    
    if(n == 0){
        return 1;
    }
    return (n * fact(n-1))%1000003;
}

int Solution::findRank(string A) {
    
    string s = A;
    sort(s.begin(),s.end());
    map<char,int> m;
    
    for(int i = 0; i < s.size(); i++){
        m[s[i]] = i;
    }
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(A[i] < s[j]){
                m[s[j]]--;
            }
        }
        if(A[i] == s[0]){
            continue;
        }
        ans = (ans + (fact(A.size()-i-1)*m[A[i]]))%1000003;
    }
    return ans+1;
}
