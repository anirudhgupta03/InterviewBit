//Method - 1
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
int Solution::maximumGap(const vector<int> &A) {
    
    vector<pair<int,int>> v;
    
    for(int i = 0; i < A.size(); i++){
        v.push_back(make_pair(A[i],i));
    }
    
    sort(v.begin(),v.end());
    
    int i = v[v.size()-1].second ,ans = 0;
    for(int j = v.size()-2; j >= 0; j--){
        ans = max(ans,i - v[j].second);
        i = max(v[j].second,i);
    }
    return ans;
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    int right[n];
    
    right[n-1] = A[n-1];
    
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1],A[i]);
    }
    
    int ans = 0, j = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        while(A[i] <= right[j] && j < A.size()){
            j++;
        }
        ans = max(ans,j-i-1);
    }
    return ans;
}
