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
    
    vector<vector<int>> res;
    
    if(A.size() < 3){
        return res;
    }
    sort(A.begin(),A.end());
    
    for(int i = 0; i <= A.size() - 3; i++){
        
        if(i != 0 && A[i] == A[i-1]){
            continue;
        }
        int l = i + 1, r = A.size() - 1;
        
        while(l < r){
            
            ll s = ((ll)A[i] + (ll)A[l] + (ll)A[r]);
            
            if(s == 0){
                vector<int> temp = {A[i],A[l],A[r]};
                res.push_back(temp);
                
                while(l < r && A[l] == A[l+1]) l++;
                while(l < r && A[r] == A[r-1]) r--;
                l++;
                r--;
            }
            else if(s < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }
    
    return res;
}
