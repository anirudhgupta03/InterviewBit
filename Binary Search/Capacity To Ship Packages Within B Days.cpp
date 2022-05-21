int daysRequiredToShip(int capacity,vector<int> &A){
    int count = 1, sum = 0;
    for(int x: A){
        sum += x;
        if(sum > capacity){
            sum = x;
            count++;
        }
    }
    return count;
}
int Solution::solve(vector<int> &A, int B) {
    int lo = 0, hi = 0;
    for(int x: A){
        lo = max(lo, x);
        hi += x;
    }
    int ans;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(daysRequiredToShip(mid, A) <= B){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
