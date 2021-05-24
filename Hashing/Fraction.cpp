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
