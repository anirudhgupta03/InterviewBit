//Method - 1
#define ll long long
string Solution::fractionToDecimal(int A, int B) {
    
    string res;
    
    string mant, cha;
    
    ll C,D;
    C = A;
    D = B;
    
    C = abs(C);
    D = abs(D);
    
    if((A < 0 && B > 0) || (A > 0 && B < 0))
        mant = "-" + to_string(C/D);
    else{
        mant = to_string(C/D);
    }
    if(C % D == 0){
        return mant;
    }
    
    C = C % D;
    
    map<pair<ll,ll>,ll> m;
    
    bool flag = false;
    
    while(C){
        
        C = C*10;
        
        if(m.find({C/D,C%D}) != m.end()){
            flag = true;
            break;
        }
        else{
            m[{C/D,C%D}] = cha.size() - 1;
        }
        cha += to_string(C/D);
        C = C % D;
    }
    
    if(flag){
        res = mant + ".";
        ll i = 0;
        
        while(i <= m[{C/D,C%D}]){
            res += cha[i];
            i++;
        }
        res += "(" + cha.substr(i,cha.size()-i) + ")";
    }
    else
        res = mant + "." + cha;
    
    return res;
}

//Method - 2
//Optimal
string Solution::fractionToDecimal(int A, int B) {
    
    bool flag = false;
    
    if(A < 0 && B > 0 || A > 0 && B < 0){
        flag = true;
    }
    
    long long a,b;
    
    a = A;
    b = B;
    
    a = abs(a);
    b = abs(b);
    
    string res;
    
    res += to_string(a/b);
    
    a %= b;
    
    if(a == 0){
        return res;
    }
    
    unordered_map<int,int> umap;
    
    res.push_back('.');

    int ind = 0;
    
    while(a){

         if(umap.find(a) != umap.end()){
             ind = umap[a];
             break;
         }
         else{
             umap[a] = ind;
         }
         
         a *= 10;
         res.push_back(a/b + '0');
         a %= b;
         ind++;
    }
    
    int i = 0;
    
    while(res[i] != '.' && i < res.size()){
        i++;
    }
    
    i++;
    while(ind){
        ind--;
        i++;
    }
    
    if(i < res.size()){
        res.insert(res.begin() + i,'(');
        res.push_back(')');
    }
    if(flag){
        res.insert(res.begin(),'-');
    }
    return res;
}
