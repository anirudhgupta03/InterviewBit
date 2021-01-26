vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    int hash[A.size()+1] = {0};
    
    for(int i = 0; i < A.size(); i++){
        hash[A[i]]++;
    }
    int miss,repeat;
    for(int i = 1; i < A.size()+1; i++){
        if(hash[i]==0){
            miss = i;
        }
        else if(hash[i]==2){
            repeat = i;
        }
    }
    vector<int> v;
    v.push_back(repeat);
    v.push_back(miss);
    return v;
}
