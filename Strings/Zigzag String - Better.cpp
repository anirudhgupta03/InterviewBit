//Method - 1
string Solution::convert(string A, int B) {
    
    if(B == 1){
        return A;
    }
    string str[B];
    
    int itr = 1, i = -1, j = 0;
    
    while(j < A.size()){
        
        if(itr % 2 == 1){
            i++;
            while(i < B && j < A.size()){
                str[i].push_back(A[j]);
                i++;
                j++;
            }
            itr++;
            i--;
        }
        else{
            i--;
            while(i >=0 && j < A.size()){
                str[i].push_back(A[j]);
                i--;
                j++;
            }
            itr++;
            i++;
        }
    }
    
    string p;
    for(int i = 0; i < B; i++){
        p += str[i];
    }
    
    return p;
}

//Method - 2
string Solution::convert(string A, int B) {
    
    if(B == 1){
        return A;
    }
    vector<string> v(B);
    int flag = -1;
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(flag == -1){
            v[count].push_back(A[i]);
            count++;
            
            if(count == B){
                flag = 1;
                count -= 2;
            }
        }
        else{
            v[count].push_back(A[i]);
            count--;
            
            if(count == -1){
                flag = -1;
                count += 2;
            }
        }
    }
    
    string res;
    for(int i = 0; i < B; i++){
        res += v[i];
    }
    return res;
}

//Method - 3
string Solution::convert(string A, int B) {
    
    if(B >= A.size() || B == 1) return A;
    vector<string> v(B);

    int i = 0, ind = 0;
    while(i < A.size()){
        while(ind < B && i < A.size()){
            v[ind].push_back(A[i]);
            ind++;
            i++;
        }
        if(ind == B){
            ind -= 2;
            while(ind >= 0 && i < A.size()){
                v[ind].push_back(A[i]);
                i++;
                ind--;
            }
        }
        if(ind == -1){
            ind += 2;
        }
    }
    string res;
    for(int i = 0; i < B; i++){
        res += v[i];
    }
    return res;
}
