bool numberofpainters(vector<int> &C,int A,long long mid){
    long long sum=0;
    A--;
    for(int i=0;i<C.size();i++){
        if(C[i]>mid) return false;
        sum=sum+C[i];
        if(sum>mid){
            sum=C[i];
            A--;
        }
    }
    cout << A << endl;
    if(A<0) return false;
    return true;
}

long long binary_search(vector<int> &C,int A){
    long long l=INT_MIN,r=0,ans;
    for(int i=0;i<C.size();i++){
        if(C[i]>l) l=C[i];
    }
    for(int i=0;i<C.size();i++){
        r=r+C[i];
    }
    while(l<=r){
         long long mid=(l+r)/2;
        
        if(numberofpainters(C,A,mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int Solution::paint(int A, int B, vector<int> &C) {
        return (binary_search(C,A)*B)%10000003;
}
