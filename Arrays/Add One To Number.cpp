//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
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

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
vector<int> Solution::plusOne(vector<int> &A) {
    
    int carry = 1, sum = 0;
    
    for(int i = A.size() - 1; i >= 0; i--){
        sum = A[i] + carry;
        A[i] = sum % 10;
        carry = sum/10;
        
        if(carry == 0){                         //Break if we get 0
            break;
        }
    }
    
    if(carry != 0){
        A.insert(A.begin(),carry);
    }

    reverse(A.begin(), A.end());
    while(A.back() == 0){
        A.pop_back();
    }
    reverse(A.begin(), A.end());
    return A;
}
