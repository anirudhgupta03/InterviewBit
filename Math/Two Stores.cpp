int Solution::solve(int A, int B, int C, int D, int E) {

    int minCost = INT_MAX, cost, sum = 0;

    while(sum <= A){
        int candiesRemaining = A - sum;
        if(candiesRemaining % D == 0){
            minCost = min(minCost, (sum/B)*C + (candiesRemaining/D)*E);
        }
        sum += B;
    }
    if(minCost == INT_MAX){
        return -1;
    }
    return minCost;
}
