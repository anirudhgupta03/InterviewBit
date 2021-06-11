//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
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

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::solve(vector<int> &A) {
    
    long long even = 0, odd = 0, e = 0, o = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(i%2==0){
            even += A[i];
        }
        else{
            odd += A[i];
        }
    }
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        
        if(i%2==0){
            e = e + A[i];
            if(o + even - e == e + odd - o - A[i]){
                count++;
            }
        }
        else{
            o = o + A[i];
            if(e + odd - o == o + even - e - A[i]){
                count++;
            }
        }
        
    }
    return count;
}

//Method - 3
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::solve(vector<int> &A) {
    
    int o = 0, e = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(i & 1){
            o += A[i];
        }
        else{
            e += A[i];
        }
    }
    
    int to = 0, te = 0;
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(i % 2 == 0){
            
            if(to + (e - te - A[i]) == te + (o-to)){
                count++;
            }
            te += A[i];
        }
        else{
            
            if(te + (o - to - A[i]) == to + (e-te)){
                count++;
            }
            to += A[i];
        }
    }
    return count;
}
