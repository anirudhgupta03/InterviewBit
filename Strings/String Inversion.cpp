string Solution::solve(string A) {

    for(int i = 0; i < A.size(); i++){
        if(islower(A[i])){
            A[i] = toupper(A[i]);
        }
        else{
            A[i] = tolower(A[i]);
        }
    }
    return A;
}
