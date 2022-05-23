//Ref: https://www.youtube.com/watch?v=oBH9dH6KGLM
#define vvll vector<vector<long long>> 
#define mod 1000000007
vvll multiplyMatrix(vvll &v1, vvll &v2){
    int m1 = v1.size(), n1 = v1[0].size();
    int m2 = v2.size(), n2 = v2[0].size();
    vvll res(m1, vector<long long>(n2, 0));

    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n2; j++){
            for(int k = 0; k < n1; k++){
                res[i][j] = (res[i][j] + (v1[i][k]*v2[k][j])%mod)%mod;
            }
        }
    }
    return res;
}
vvll matrixExponentiate(vvll &a, int n){

    if(n == 0){
        return {{1,0},{0,1}};
    }
    if(n == 1){
        return a;
    }
    vvll temp1 = matrixExponentiate(a, n/2);
    vvll temp2 = multiplyMatrix(temp1, temp1);
    if(n % 2 == 0) return temp2;
    return multiplyMatrix(a, temp2);
}
int Solution::solve(int A) {

    vvll a = {{1,1},{1,0}};

    vvll ans = matrixExponentiate(a, A);

    return ans[0][1];
}
