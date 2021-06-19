//Time Complexity - O(NlogN)
//Space Complexity - O(1)
int Solution::threeSumClosest(vector<int> &A, int B) {
    
    int n = A.size();
    
    if(n < 3){
      return 0;
    }
    sort(A.begin(),A.end());
    
    int diff = INT_MAX, sum;
    
    for(int i = 0; i <= n - 3; i++){
        
        int l = i + 1, r = n - 1;
        
        while(l < r){
            
            int s = A[i] + A[l] + A[r];
            
            if(s == B){
                return B;
            }
            else if(s < B){
                if(B - s < diff){
                    diff = B - s;
                    sum = s;
                }
                l++;
            }
            else{
                if(s - B < diff){
                    diff = s - B;
                    sum = s;
                }
                r--;
            }
        }
    }
    return sum;
}
