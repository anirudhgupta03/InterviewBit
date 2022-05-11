//Using Priority Queue
//Time Complexity - O(NlogK)
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

//Using Deque
//Time Complexity - O(N)
//Space Complexity - O(1)
vector<int> Solution::slidingMaximum(const vector<int> &nums, int k) {
    
    vector<int> res;
        
        deque<int> dq;
        
        int i = 0, j = 0;
        
        while(j < nums.size()){
            
            if(dq.empty()){
                dq.push_back(nums[j]);
            }
            else if(dq.back() < nums[j]){
                
                while(!dq.empty() && dq.back() < nums[j]){
                    dq.pop_back();
                }
                
                dq.push_back(nums[j]);
            }
            else{
                dq.push_back(nums[j]);
            }
            
            if(j - i + 1  < k){
                j++;
            }
            else if(j - i + 1 == k){
                
                res.push_back(dq.front());
                
                if(nums[i] == dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return res;
}

//Method - 3
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    if(B >= A.size()){
        int maxEle = INT_MIN;
        for(int i = 0; i < A.size(); i++){
            maxEle = max(maxEle, A[i]);
        }
        vector<int> res = {maxEle};
        return res;
    }
    deque<int> dq;

    for(int i = 0; i < B - 1; i++){
        while(!dq.empty() && A[i] > dq.back()){
            dq.pop_back();
        }
        dq.push_back(A[i]);
    }
    vector<int> res;

    for(int i = B - 1; i < A.size(); i++){
        while(!dq.empty() && A[i] > dq.back()){
            dq.pop_back();
        }
        dq.push_back(A[i]);
        res.push_back(dq.front());
        if(dq.front() == A[i - B + 1]){
            dq.pop_front();
        }
    }
    return res;
}
