long double dist(pair<long double, long double> a, pair<long double, long double> b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
bool check(long double r, vector<pair<long double, long double>> &v, int B){
    r *= r;
    int n = v.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long double h = dist(v[i], v[j]);
            long double D = (4*r - h)/h;

            if(4*r - h >= 0.0){
                int cnt1 = 2;
                int cnt2 = 2;

                pair<long double, long double> p1, p2;

                p1.first = (v[i].first + v[j].first)/2 + (sqrt(D)*(v[i].second - v[j].second))/2;
                p1.second = (v[i].second + v[j].second)/2  + (sqrt(D)*(v[j].first - v[i].first))/2;
                p2.first = (v[i].first + v[j].first)/2 - (sqrt(D)*(v[i].second - v[j].second))/2;
                p2.second = (v[i].second + v[j].second)/2  - (sqrt(D)*(v[j].first - v[i].first))/2;

                for(int k = 0; k < v.size(); k++){
                    if(k == i || k == j) continue;
                    if(dist(p1, v[k]) <= r) cnt1++;
                    if(dist(p2, v[k]) <= r) cnt2++;
                }

                if(cnt1 >= B || cnt2 >= B){
                    return true;
                }
            }
        }
    }
    return false;
}
int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    vector<pair<long double, long double>> v(n);
    for(int i = 0; i < n; i++){
        v[i] = {1.0*A[i][0], 1.0*A[i][1]};
    }    
    int lo = 1, hi = 2000000000, ans;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(check(mid, v, B)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }    
    return ans;
}
