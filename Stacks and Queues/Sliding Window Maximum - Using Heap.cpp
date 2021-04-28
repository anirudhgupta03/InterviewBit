#define pii pair<int,int>

int add(priority_queue<pii> &pq, int ele, int index, int B){
    pq.push({ele,index});
    
    while(pq.top().second <= abs(index-B)){
        pq.pop();
    }
    
    return pq.top().first;
}
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    priority_queue<pii> pq;
    
    vector<int> v;
    
    if(B > A.size()){
        return v;
    }
    
    for(int i = 0; i < B; i++){
        pq.push({A[i],i});
    }
    
    v.push_back(pq.top().first);
    
    for(int i = B; i < A.size(); i++){
        v.push_back(add(pq,A[i],i,B));
    }
    
    return v;
}
