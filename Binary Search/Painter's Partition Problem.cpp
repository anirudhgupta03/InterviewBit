long long number_of_painters(vector<int> C, int t){
    
    long long count = 1, sum = 0;
    for(auto x : C){
        
        sum += x;
        
        if(sum > t){
            sum = x;
            count++;
        }
    }
    
    return count;
}
int Solution::paint(int A, int B, vector<int> &C) {
    
    int l = INT_MIN;
    long long r = 0;
    
    for(auto x : C){
        r = r+ x;
        l = max(l,x);
    }
    long long ans;
    while(l<=r){
        
        long long mid = (l+r)/2;
        
        if(number_of_painters(C,mid) > A){
            l = mid + 1;
        }
        else if(number_of_painters(C,mid) <= A){
            r = mid - 1;
            ans = mid;
        }
    }
    return (ans*B)%10000003;
}
