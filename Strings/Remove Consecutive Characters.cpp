//Time Complexity - O(N^2)
//Space Complexity - O(1)
string Solution::solve(string A, int B) {
    
    int n = A.size();
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i] != A[i-1]){
            A.insert(A.begin()+i,' ');     //Costly Operation insert(): Inserts additional characters into the string at a particular position. Its time complexity is O(N) where N is the size of the new string.
            i++;
        }
    }
    
    int count = 0;
    stringstream X(A);
    string temp,res;
    
    while(X >> temp){
        if(temp.size() != B){
            res += temp;
        }
    }
    return res;
}
//Time Complexity - O(N)
//Space Complexity - O(1)
//Optimal Approach
string Solution::solve(string A, int B) {
    
    string ans;
    
    int i = 0;
    
    while(i < A.size()){
        
        string temp;
        
        int j = i;
        
        while(i < A.size() && A[i] == A[j]){
            temp += A[i];
            i++;
        }
        
        if(temp.length() != B){
            ans += temp;
        }
    }
    
    return ans;
}

