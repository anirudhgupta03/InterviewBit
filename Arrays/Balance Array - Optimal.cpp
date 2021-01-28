int Solution::solve(vector<int> &A) {
    
    long long even = 0, odd = 0, e = 0, o = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(i%2==0){
            even += A[i];
        }
        else{
            odd += A[i];
        }
    }
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        
        if(i%2==0){
            e = e + A[i];
            if(o + even - e == e + odd - o - A[i]){
                count++;
            }
        }
        else{
            o = o + A[i];
            if(e + odd - o == o + even - e - A[i]){
                count++;
            }
        }
        
    }
    return count;
}
