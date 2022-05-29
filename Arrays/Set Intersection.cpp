//Ref: https://leetcode.com/problems/set-intersection-size-at-least-two/discuss/1600527/Clean-code-with-comments
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[1] == v2[1]){
        return v1[0] > v2[0];
    }
    return v1[1] < v2[1];
}
int Solution::setIntersection(vector<vector<int> > &A) {
    
    int n = A.size();
    
    sort(A.begin(), A.end(), cmp);

    int ans = 0, p1 = -1, p2 = -1;

    for(int i = 0; i < n; i++){
        if(A[i][0] <= p1) continue;

        if(A[i][0] > p2){
            ans += 2;
            p2 = A[i][1];
            p1 = p2 - 1;
        }
        else{
            ans++;
            p1 = p2;
            p2 = A[i][1];
        }
    }
    return ans;
}
