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
