int Solution::solve(vector<int> &A, int B, int C) {

    int odd = 0, even = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] % 2 == 0) even++;
        else    odd++;
    }

    if(B % 2 == 0){
        return odd*C;
    }
    else{
        return even*C;
    }
}
