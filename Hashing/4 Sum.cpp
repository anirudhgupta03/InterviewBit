//Method - 1
//Time Complexity - O(N^3logN)
//Space Complexity - O(N)
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    set<vector<int>> s;
    
    vector<vector<int>> res;
    
    if(A.size() < 4){
        return res;
    }
    sort(A.begin(),A.end());
    
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    
    while(p1 <= A.size() - 4){
        
        p2 = p1 + 1;
        
        while(p2 <= A.size() - 3){
            
            p3 = p2 + 1;
            p4 = A.size() - 1;
            
            while(p3 < p4){
                
                int sum = A[p1] + A[p2] + A[p3] + A[p4];
                
                if(sum == B){
                    
                    vector<int> temp;
                    temp.push_back(A[p1]);
                    temp.push_back(A[p2]);
                    temp.push_back(A[p3]);
                    temp.push_back(A[p4]);
                    s.insert(temp);
                    
                    p3++;
                    p4--;
                }
                else if(sum < B){
                    p3++;
                }
                else{
                    p4--;
                }
            }
            
            p2++;
        }
        p1++;
    }
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it != s.end(); it++){
        res.push_back(*it);
    }
    return res;
}

//Method - 2
//Optimal Approach
//Time Complexity - O(N^3)
//Space Complexity - O(1)
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());

    vector<vector<int>> res;
    
    int n = A.size();
    
    if(n < 4){
        return res;
    }
    
    for(int i = 0; i <= n - 3; i++){
        if(i > 0 && A[i] == A[i-1]){
            continue;
        }
        for(int j = i + 1; j <= n - 2; j++){
            
            if(j > i + 1 && A[j] == A[j-1]){
                continue;
            }
            int lo = j + 1, hi = n - 1;
            
            while(lo < hi){
                
                int sum = A[i] + A[j] + A[lo] + A[hi];
                
                if(sum < B){
                    lo++;
                }
                else if(sum > B){
                    hi--;
                }
                else{
                    vector<int> temp = {A[i],A[j],A[lo],A[hi]};
                    res.push_back(temp);
                    while(lo < hi && A[lo] == A[lo+1]) lo++;
                    lo++;
                    while(lo < hi && A[hi] == A[hi-1]) hi--;
                    hi--;
                }
            }
        }
    }
    return res;
}
