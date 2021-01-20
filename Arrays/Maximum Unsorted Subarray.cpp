vector<int> Solution::subUnsort(vector<int> &A) {
    
    int start, end, flag = 1;
    vector<int> v;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < A[i-1]){
            start = i - 1;
            flag = 0;
            break;
        }
    }
    
    if(flag == 1){
        v.push_back(-1);
        return v;
    }
    
    for(int i = A.size()-1; i>=1; i--){
        if(A[i] < A[i-1]){
            end = i;
            break;
        }
    }
    
    int mx,mn;
    mx = mn = A[start];
    
    for(int j = start+1; j <= end; j++){
        mx = max(mx,A[j]);
        mn = min(mn,A[j]);
    }
    
    for(int i = 0; i< start; i++){
        if(A[i] > mn){
            start = i;
            break;
        }
    }
    
    for(int j = A.size()-1; j > end; j--){
        if(A[j] < mx){
            end = j;
            break;
        }
    }
    
    v.push_back(start);
    v.push_back(end);
    return v;
}
