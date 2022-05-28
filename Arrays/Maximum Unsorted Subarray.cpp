//Method - 1
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

//Method - 2
//Optimal Approach
vector<int> Solution::subUnsort(vector<int> &A) {

    int n = A.size();

    int end = -1, maxLeft = A[0];

    for(int i = 1; i < n; i++){
        if(A[i] < maxLeft){
            end = i;
        }
        else{
            maxLeft = A[i];
        }
    }

    int start = -1, minRight = A[n - 1];

    for(int i = n - 2; i >= 0; i--){
        if(A[i] > minRight){
            start = i;
        }
        else{
            minRight = A[i];
        }
    }
    vector<int> res;
    if(start == -1 || end == -1){
        res.push_back(-1);
    }
    else{
        res.push_back(start);
        res.push_back(end);
    }
    return res;
}
