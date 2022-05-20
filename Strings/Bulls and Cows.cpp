string Solution::solve(string A, string B) {

    int alpha[10] = {0};

    for(int i = 0; i < A.size(); i++){
        alpha[A[i] - '0']++;
    }

    int bulls = 0, cows = 0;

    for(int i = 0; i < B.size(); i++){
        if(A[i] == B[i]){
            bulls++;
            alpha[A[i] - '0']--;
        }
    }
    for(int i = 0; i < B.size(); i++){
        if(A[i] != B[i]){
            if(alpha[B[i] - '0']){
                cows++;
                alpha[B[i] - '0']--;
            }
        }
    }
    string res = to_string(bulls) + "A" + to_string(cows) + "B";
    return res;
}
