vector<int> Solution::maxset(vector<int> &A) {
    
    vector<int> v1,v2;
    
    long long curr_sum=0,max_sum=0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] < 0){
            curr_sum = 0;
            v2.clear();
            continue;
        }
        
        curr_sum = curr_sum+A[i];
        v2.push_back(A[i]);
        
        if(curr_sum == max_sum){
            if(v2.size()>v1.size()){
                v1.clear();
                    for(int j = 0; j <v2.size(); j++){
                        v1.push_back(v2[j]);
                    }
            }
        }
        else if(curr_sum>max_sum ){
            max_sum=curr_sum;
            v1.clear();
            for(int j = 0; j<v2.size(); j++){
                v1.push_back(v2[j]);
            }
        }
    }
    
    return v1;
}
