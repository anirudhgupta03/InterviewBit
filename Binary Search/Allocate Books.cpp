long long numberofstudents(vector<int> A,long long pages){
    
    long long count = 1, sum = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        sum = sum + A[i];
        
        if(sum > pages){
            count++;
            sum = A[i];
        }
    }
    return count;
}
int Solution::books(vector<int> &A, int B) {
    
    long long l = INT_MIN, r = 0;
    
    if(A.size() < B){
        return -1;
    }
    for(auto x : A){
        
        if(x > l){
            l = x;
        }
        
        r = r + x;
    }
    int ans;
    
    while(l<=r){
        
        long long mid = (l+r)/2;
        
        if(numberofstudents(A,mid) > B){
            l = mid + 1;
        }
        else if(numberofstudents(A,mid) <= B){
            ans = mid;
            r = mid - 1;
        }
    }
    
    return ans;
}
