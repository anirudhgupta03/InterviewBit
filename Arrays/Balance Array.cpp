int Solution::solve(vector<int> &A) {
    
    long long even[A.size()], odd[A.size()], sum = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(i % 2==0){
            sum = sum + A[i];
        }
        even[i] = sum;
    }
    
    sum = 0;
    for(int i = 0; i < A.size(); i++){
        
        if(i % 2==1){
            sum = sum + A[i];
        }
        odd[i] = sum;
    }
 
    int count = 0;
    
    if(even[A.size()-1]- A[0] == odd[A.size() -1]){
        count++;
    }
    for(int i = 1; i < A.size(); i++){
        
        if(even[i-1] + odd[A.size()-1] - odd[i] == odd[i-1] + even[A.size()-1] - even[i]){
            count++;
        }
    }
    return count;
}
