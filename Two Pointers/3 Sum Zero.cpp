//Method - 1
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    int n = A.size();
    
    sort(A.begin(),A.end());
    
    vector<vector<int>> res;
    
    for(int i = 0; i < n - 1; i++)
    {
        
        if(i != 0 && A[i] == A[i-1])
        {
            continue;
        }
        
        int low = i + 1, high = A.size() - 1;
        
        while(low < high)
        {
            
            if(0LL + A[i] +A[low] + A[high] == 0)
            {
                
                res.push_back({A[i],A[low],A[high]});
                
                while(low < high && A[low] == A[low + 1])
                {
                    low++;
                }
                while(low < high && A[high] == A[high - 1])
                {
                    high--;
                }
                low++;
                high--;
            }
            else if(0LL + A[i] + A[high] + A[low] < 0)
            {
                low++;
            }
            else{
                high--;
            }
        }
    }
    return res;
}

//Method - 2
#define ll long long
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    
    for(int i = 0; i < A.size(); i++){
        if(i && A[i] == A[i - 1]) continue;
        
        int lo = i + 1, hi = A.size() - 1;
        while(lo < hi){
            ll sum = (ll)A[i] + (ll)A[lo] + (ll)A[hi];
            if(sum == 0){
                res.push_back({A[i], A[lo], A[hi]});
                lo++;
                hi--;
                while(lo < hi && A[lo] == A[lo - 1]) lo++;
                while(lo < hi && A[hi] == A[hi + 1]) hi--;
            }
            else if(sum > 0){
                hi--;
            }
            else{
                lo++;
            }
        }
    }
    return res;
}
