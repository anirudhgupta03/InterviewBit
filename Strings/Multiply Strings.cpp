string Solution::multiply(string A, string B) {
    
    int m = A.length(), n = B.length();
    
    int val[m+n];
    memset(val,0,sizeof(val));
    
    for(int i = m - 1; i >=0; i--){
        for(int j = n - 1; j >= 0; j--){
            
            int mult = (A[i] - '0')*(B[j] - '0');
            int sum = val[i+j+1] + mult;
            val[i+j] += sum / 10;
            val[i+j+1] = sum % 10;
        }
    }
    string s;
    int i = 0;
    while(i < m + n){
        if(val[i] != 0){
            break;
        }
        i++;
    }
    if(i == m + n){
        return "0";
    }
    for(int j = i; j < m + n; j++){
        string p = to_string(val[j]);
        s += p;
    }
    return s;
    
}
