int Solution::solve(string A) {

    if(A.size() < 8 || A.size() > 15) return 0;

    bool digit = false, lowerch = false, upperch = false, special = false;

    for(int i = 0; i < A.size(); i++){
        if(isdigit(A[i])) digit = true;
        else if(islower(A[i])) lowerch = true;
        else if(isupper(A[i])) upperch = true;
        else special = true;
    }
    if(!digit || !lowerch || !upperch || !special) return 0;
    return 1;
}
