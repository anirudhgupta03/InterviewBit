//Ref: https://www.interviewbit.com/problems/rod-cutting/discussion/p/c-accepted-intiutve-comments-for-explanation/268928/1003
#define ll long long
ll MinCost(int st, int end, vector<int> &cuts, vector<vector<ll>> &dp, vector<vector<int>> &cut){
    
    if(abs(end - st) <= 1) return 0;
    if(dp[st][end] != -1) return dp[st][end];
    
    ll ans = LLONG_MAX;
    for(int i = st + 1; i < end; i++){
        ll a = cuts[end] - cuts[st] + MinCost(st, i, cuts, dp, cut) + MinCost(i, end, cuts, dp, cut);
        if(ans > a){
            cut[st][end] = i;
            ans = a;
        }
    }
    dp[st][end] = ans;
    return ans;
}
void Fill(vector<int> &ans, vector<vector<int > > &cut, vector<int> &cuts, int st, int end){
    if(abs(end - st) <= 1)
        return;
    ans.push_back(cuts[cut[st][end]]);
    Fill(ans, cut, cuts, st, cut[st][end]);
    Fill(ans, cut, cuts,cut[st][end], end);
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    
    B.insert(B.begin(), 0);
    B.push_back(A);
    int m = B.size();
    
    vector<vector<ll>> dp(m, vector<ll>(m, - 1));
    vector<vector<int>> cut(m, vector<int>(m));
    MinCost(0, m - 1, B, dp, cut);
    vector<int> ans;
    Fill(ans, cut, B, 0, m - 1);
    return ans;
}
