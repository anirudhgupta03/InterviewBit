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
