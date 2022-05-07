//Method - 1
string Solution::getPermutation(int A, int B) {
    
    int fact[A+1];
    
    fact[0] = 1;
    
    fact[1] = 1;
    
    for(int i = 2; i < A + 1; i++){
        if(i > 12) fact[i] = INT_MAX;
        else fact[i] = i*fact[i-1];
    }
    
    string s;
    
    vector<int> v(A);
    
    for(int i = 0; i < A; i++){
        v[i] = i+1;
    }
    
    int index;
    
    int n = A;
    
    while(A){
        
        index = B / fact[A-1];
        
        if(B % fact[A-1] == 0){
            index--;
        }
        
        s += to_string(v[index]);
        
        v.erase(v.begin()+index);
        
        B -= index*fact[A-1];
        
        A--;
    }
    return s;
}

//Method - 2
string Solution::getPermutation(int A, int B) {

    if(A == 1){
        return "1";
    }
    int fact[A+1];
    
    fact[0] = 1;
    fact[1] = 1;
    
    for(int i = 2; i < A + 1; i++){
        if(i > 12) fact[i] = INT_MAX;
        else fact[i] = i*fact[i-1];
    }

    vector<int> v(A);
    for(int i = 0; i < A; i++){
        v[i] = i + 1;
    }

    string res;
    int i = A - 1;

    while(B){
        int temp = B/fact[i];
        if(B % fact[i] == 0){
            temp--;
        }
        res += to_string(v[temp]);

        v.erase(v.begin() + temp);
        B %= fact[i];
        i--;
    }
    for(int i = v.size() - 1; i >= 0; i--){
        res += to_string(v[i]);
    }
    return res;
}
