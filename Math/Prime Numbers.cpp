vector<int> Solution::sieve(int A) {

    bool primes[A+1];
    memset(primes,true,sizeof(primes));
    primes[1] = false;
    
    for(int p = 2; p*p <= A; p++){
        if(primes[p]==true){    
            for(int i= p*p ;i <= A;i+=p){
                primes[p]=false;
            }
        }
    }
    
    vector<int> v;
    
    for(int p=2;p<=A;p++){
        if(primes[p]==true){
            v.push_back(p);
        }
    }
    
    return v;
}
