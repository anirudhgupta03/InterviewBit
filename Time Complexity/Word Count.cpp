int Solution::solve(string A) {

    stringstream X(A);
    string temp;
    int count = 0;

    while(X >> temp){
        count++;
    }
    return count;
}
