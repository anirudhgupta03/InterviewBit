vector<int> Solution::solve(vector<int> &A, int B) {

    int n = A.size();
    vector<int> pos(n + 1);

    for(int i = 0; i < n; i++){
        pos[A[i]] = i;
    }

    for(int i = 0; i < n; i++){
        if(A[i] != n - i){
            B--;
            int ind = pos[n - i];
            A[ind] = A[i];
            A[i] = n - i;
            pos[A[ind]] = ind;
            pos[A[i]] = i;
        }
        if(B == 0){
            break;
        }
    }
    return A;
}
