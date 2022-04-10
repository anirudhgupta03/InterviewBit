#define ll long long
int Solution::nchoc(int A, vector<int> &B) {

    priority_queue<int> bag;

    for(int i = 0; i < B.size(); i++){
        bag.push(B[i]);
    }
    int mod = 1e9 + 7;
    ll sum = 0;

    while(!bag.empty() && A--){
        int curr = bag.top();
        bag.pop();

        sum = (sum + curr)%mod;

        curr /= 2;
        if(curr) bag.push(curr);
    }
    return sum;
}
