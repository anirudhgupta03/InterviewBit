//Using Max Heap
#define ll long long
int Solution::nchoc(int A, vector<int> &B) {
    
    priority_queue<int> pq;
    
    for(int i = 0; i < B.size(); i++){
        pq.push(B[i]);
    }
    
    ll count = 0, ans = 0;
    
    while(count != A && pq.size()){
        
        ll temp = pq.top();
        
        ans =  (ans + temp)%1000000007;
        
        count++;
        
        pq.pop();
        
        pq.push(floor(temp/2));
    }
    return ans;
}
