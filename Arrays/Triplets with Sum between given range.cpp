int Solution::solve(vector<string> &A) {

    int n = A.size();

    if(n<3) return 0;
    
    sort(A.begin(), A.end());

    int l = 0, r = n-1;

    while(l < r - 1){
        
        float s = stof(A[l]) + stof(A[l+1]) + stof(A[r]);
        
        if(s >= 2){
            r = r - 1;
        }
        else if(s <= 1){
            l = l + 1;
        }
        else{
            return 1;
        }
    }
    return 0;
}
