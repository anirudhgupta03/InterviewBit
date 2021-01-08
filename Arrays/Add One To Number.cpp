vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size();
    vector<int> v(n);
    
    int carry=(A[n-1]+1)/10;
    v[n-1]=(A[n-1]+1)%10;
    
    for(int i=n-2;i>=0;i--){
        v[i]=(A[i]+carry)%10;
        carry=(A[i]+carry)/10;
    }
    
    if(carry==0){
        vector<int> v2;
        int i=0;
        while(v[i]==0){
            i++;
        }
        for(int j=i;j<n;j++){
            v2.push_back(v[j]);
        }
        return v2;
    }
    else{
        vector<int> v1(n+1);
        v1[0]=carry;
        for(int i=0;i<n;i++){
            v1[i+1]=v[i];
        }
        return v1;
    }
}
