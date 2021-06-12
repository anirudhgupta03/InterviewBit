//Method - 1
int Solution::compareVersion(string A, string B) {
    
    int i = 0, j = 0;
    
    int n1 = A.size(), n2 = B.size();
    
    while(i < n1 || j < n2)
    {
        string s1, s2;
        
        while(A[i] != '.' && i < n1){
            
            if(s1.size() == 0 && A[i] == '0'){
                i++;
                continue;
            }
            s1 += A[i];
            i++;
        }
        i++;
        while(B[j] != '.' && j < B.size()){
            
            if(s2.size() == 0 && B[j] == '0'){
                j++;
                continue;
            }
            s2 += B[j];
            j++;
        }
        j++;
        if(s1.size() > s2.size()){
            return 1;
        }
        else if(s1.size() < s2.size()){
            return -1;
        }
        else{
            if(s1>s2) return 1;
            else if(s1<s2) return -1;
        }
    }
    return 0;
}

//Method - 2
int Solution::compareVersion(string A, string B) {
    
    vector<double> v1,v2;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '.'){
            A[i] = ' ';
        }
    }
    for(int i = 0; i < B.size(); i++){
        if(B[i] == '.'){
            B[i] = ' ';
        }
    }
    stringstream X1(A);
    string temp;
    while(X1 >> temp){
        v1.push_back(stod(temp));
    }
    
    stringstream X2(B);
    while(X2 >> temp){
        v2.push_back(stod(temp));
    }
    
    if(v1.size() > v2.size()){
        while(v2.size() != v1.size()){
            v2.push_back(0);
        }
    }
    else{
        while(v1.size() != v2.size()){
            v1.push_back(0);
        }
    }
    
    for(int i = 0; i < v1.size(); i++){
        if(v1[i] > v2[i]){
            return 1;
        }
        else if(v2[i] > v1[i]){
            return -1;
        }
    }
    return 0;
}
