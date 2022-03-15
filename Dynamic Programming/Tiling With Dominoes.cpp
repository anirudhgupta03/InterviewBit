//Ref: Solution Approach
#define M 1000000007
int Solution::solve(int n) {
    if(n%2!=0)  return 0;
    long long Anext=0, Aprev=1, Bnext=0, Bprev=1;
    for(int i=2; i<=n; i+=2){
        Anext=(Aprev+2*Bprev)%M;
        Aprev=Anext;
        Bnext=(Aprev+Bprev)%M;
        Bprev=Bnext;
    }
    return Anext;
}
