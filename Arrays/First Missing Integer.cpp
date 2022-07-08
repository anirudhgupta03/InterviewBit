//Brute Force Approach
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
int Solution::firstMissingPositive(vector<int> &A) {
    
    int num = 1;
    
    sort(A.begin(),A.end());
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] > 0 && A[i]!=num){
            return num;
        }
        else if(A[i] > 0 && A[i] == num){
            num++;
        }
        
    }
    return num;
}

//Better Approach
//Time Complexity - O(N)
//Space Complexity - O(N)  
//numbers A[i]<=0 and A[i]>N ( N being the size of the array ) is not important to us since the missing positive integer will be in the range [1, N+1].
//The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].

int Solution::firstMissingPositive(vector<int> &A) {
    
    int n = A.size();
    
    vector<int> temp(n+1,0);
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] > 0 && A[i] <= n){
            temp[A[i]]++;
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(temp[i] == 0){
            return i;
        }
    }
    return n + 1;
}

//Optimal Approach 1
//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=-lfHWWMmXXM
int Solution::firstMissingPositive(vector<int> &A) {
    
    for(int i = 0; i < A.size(); i++){
        
        while(A[i] != i+1 && A[i] <= A.size() && A[i] > 0){
            if(A[i] != A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else 
                break;
        }
        
    }
    
    for(int i = 0; i < A.size(); i++){
        if(A[i]!=i+1){
            return i+1;
        }
    }
    return A.size()+1;
}

//Optimal Approach 2
int Solution::firstMissingPositive(vector<int> &A) {

    int n = A.size();

    for(int i = 0; i < n; i++){

        int correctPos = A[i] - 1;

        while(correctPos >= 0 && correctPos <= n - 1 && A[i] != A[correctPos]){
            swap(A[i], A[correctPos]);
            correctPos = A[i] - 1;
        }
    }

    for(int i = 0; i < n; i++){
        if(A[i] != i + 1){
            return i + 1;
        }
    }
    return n + 1;
}

//Optimal Approach 3
int Solution::firstMissingPositive(vector<int> &A) {
    
    int n = A.size();
    
    for(int i = 0; i < n; i++){
        if(A[i] == i + 1) continue;
        
        while(1){
            if(A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]) break;
            swap(A[i], A[A[i] - 1]);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(A[i] != i + 1) return i + 1;
    }
    return n + 1;
}
