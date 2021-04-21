//Use NSL and NSR approach
int Solution::largestRectangleArea(vector<int> &A) {
    
    int n = A.size();
    vector<int> nsl;
    nsl.push_back(-1);
    
    stack<pair<int,int>> s;
    s.push({A[0],0});
    
    for(int i = 1; i < A.size(); i++){
        
        if(s.top().first < A[i]){
            nsl.push_back(s.top().second);
        }
        else{
            
            while(!s.empty() && s.top().first >= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(s.top().second);
            }
        }
        s.push({A[i],i});
    }
    
    vector<int> nsr;
    nsr.push_back(A.size());

    while(s.size()){
        s.pop();
    }
    s.push({A[A.size()-1],A.size()-1});
    
    for(int i = A.size() - 2; i >= 0; i--){
        
        if(s.top().first < A[i]){
            nsr.push_back(s.top().second);
        }
        else{
            
            while(!s.empty() && s.top().first >= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                nsr.push_back(A.size());
            }
            else{
                nsr.push_back(s.top().second);
            }
        }
        s.push({A[i],i});
    }
    reverse(nsr.begin(),nsr.end());
    int ans = INT_MIN;
    
    for(int i = 0; i < A.size(); i++){
        
        int larea = (i - nsl[i] - 1)*A[i];
        int rarea = (nsr[i] - i - 1)*A[i];
        
        ans = max(ans, larea+rarea+A[i]);
    }
    
    return ans;
}
