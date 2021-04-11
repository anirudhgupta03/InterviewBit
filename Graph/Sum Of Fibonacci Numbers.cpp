int Solution::fibsum(int A) {
    
    vector<int> fib;
    
    fib.push_back(0);
    fib.push_back(1);
    
    int i = 2;
    while(1){
        int val = fib[i-1] + fib[i-2];
        
        if(val > A){
            break;
        }
        fib.push_back(val);
        i++;
    }
    
    int count = 0, j = fib.size() - 1;
    
    while(A){
        count += (A/fib[j]);
        A = A % fib[j];
        j--;
    }
    return count;
}
