// If the number of students is lesser or equal than the number of students then return true in numberofbooks
// function else return false

// Also if the number of students is greater than the number of books then return -1

//Method - 1
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

//Method - 2
bool isPossible(int pages, vector<int> &A, int B){
    
    int count = 1;
    
    int sum = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        sum += A[i];
        
        if(sum > pages){
            count++;
            sum = A[i];
        }
    }
    
    if(count > B){
        return false;
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    
    if(B > A.size()){
        return -1;
    }
    int lo = INT_MIN, hi = 0;
    
    for(int i = 0; i < A.size(); i++){
        lo = max(lo,A[i]);
        hi += A[i];
    }
    
    int ans;
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(isPossible(mid,A,B)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
