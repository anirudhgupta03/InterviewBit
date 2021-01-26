vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    int arr[A.size()];
    
    for(int i = 0; i < A.size(); i++){
        arr[i] = A[i];
    }
    
    int miss, repeat;
    for(int i = 0; i < A.size(); i++){
        
        int j = abs(arr[i])-1;
        if(arr[j] < 0){
            repeat = j+1;
        }
        arr[j] = -abs(arr[j]);
    }
    
    for(int i = 0; i < A.size(); i++){
        
        if(arr[i] > 0){
            miss = i+1;
        }
    }
    
    vector<int> v;
    v.push_back(repeat);
    v.push_back(miss);
    
    return v;
}   
