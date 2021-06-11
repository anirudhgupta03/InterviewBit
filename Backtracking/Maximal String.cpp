//Method - 1
void maximalstring(int ind,string &ans, string &A, int B,int &count){
    
    if(count <= B){
        if(A > ans){
            ans = A;
        }
        if(count == B)
            return;
    }
    
    for(int i = ind; i < A.size() ; i++){
        for(int j = ind + 1; j < A.size(); j++){
            if(A[j] > A[i]){
              swap(A[i],A[j]);
              count++;
              maximalstring(ind + 1,ans,A,B,count);
              swap(A[i],A[j]);
              count--;
            }
        }
    }
}

string Solution::solve(string A, int B) {
    
    if(A.size() == 1){
        return A;
    }
    
    if(A.size() == 2){
        
    }
    string ans = A;
    int count = 0;
    maximalstring(0,ans,A,B,count);
    
    return ans;
}

//Method - 2
//Optimal Approach
//Similar to permutation of a string
void maximalString(int ind, string &ans, string &A, int B){
    
    //cout << A << endl;
    if(B >= 0){
       if(A > ans){
           ans = A;
       }
       if(B == 0){
           return;
       }
    }
    
    for(int j = ind; j < A.size(); j++){
        
        if(j == ind)                          //Swapping with itself is not considered here so just increase ind
            maximalString(ind+1,ans,A,B);
        else{
            swap(A[ind],A[j]);
            maximalString(ind+1,ans,A,B-1);   //Swapping with another element and decreasing the number of total swaps
            swap(A[ind],A[j]);
        }
    }
}
string Solution::solve(string A, int B) {
    
    string ans = A;
    
    maximalString(0,ans,A,B);
    
    return ans;
}
