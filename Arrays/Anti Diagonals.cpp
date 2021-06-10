//Method - 1
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector<vector<int>> v1;
    
    int i = 0, j = 0;
    
    while(1){
        
        if(i >= A.size()){
            break;
        }
        
        vector<int> v;
        for(int p = j, l =0 ; p>=0 , l <=i; p--,l++){
            v.push_back(A[l][p]);
        }
        
        v1.push_back(v);
        i++;
        j++;
    }
    
    i =1 , j =1;
    
    while(1){
        if(i >= A.size()){
            break;
        }
        
        vector<int> v;
        for(int p = A.size() -1, l =i ; p>=j , l <A.size(); p--,l++){
            v.push_back(A[l][p]);
        }
        
        v1.push_back(v);
        i++;
        j++;
    }
    
    return v1;
}

//Method - 2
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector<vector<int>> res;
    
    int j = 0;
    
    while(j < n){
        
        vector<int> temp;
        
        int p = 0;
        
        for(int k = j; k >= 0; k--){
            temp.push_back(A[p][k]);
            p++;
        }
        
        res.push_back(temp);
        j++;
    }
    
    int i = 1;
    
    while(i < n){
        
        vector<int> temp;
        
        int p = i;
        
        for(int k =  n - 1; k >= i; k--){
            temp.push_back(A[p][k]);
            p++;
        }
        
        res.push_back(temp);
        i++;
    }
    
    return res;
}
