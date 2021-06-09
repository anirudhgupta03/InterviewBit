vector<int> Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    unordered_map<int,int> myumap;
    
    for(int i = 0; i < A.size(); i++){
        myumap[A[i]] = i;
    }
    
    for(int i = 0; i < A.size(); i++){
        
        if(B > 0){
            
            if(A[i] != n - i){
                
                int pos1 = i;
                int pos2 = myumap[n-i];
                
                myumap[A[i]] = pos2;
                myumap[n-i] = pos1;
                
                swap(A[pos1],A[pos2]);
                
                B--;
            }
        }
        else{
            break;
        }
    }
    return A;
}
