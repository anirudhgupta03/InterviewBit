//Ref: https://www.youtube.com/watch?v=vtJvbRlHqTA
int Solution::maxProduct(const vector<int> &A) {

    int prev_max_prod = A[0], prev_min_prod = A[0];
    int curr_max_prod = A[0], curr_min_prod = A[0];

    int ans = A[0]; 

    for(int i = 1; i < A.size(); i++){

        curr_max_prod = max({prev_max_prod*A[i], prev_min_prod*A[i],A[i]});
        curr_min_prod = min({prev_max_prod*A[i], prev_min_prod*A[i],A[i]});
        
        ans = max(curr_max_prod,ans);
        
        prev_max_prod = curr_max_prod;
        prev_min_prod = curr_min_prod;
    }

    return ans;
}
