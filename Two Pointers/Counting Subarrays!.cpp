//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(1)

int Solution::solve(vector<int> &A, int B) {
    int count=0;
    
    for(int i=0;i<A.size();i++){
        int j=i,sum=A[i];
        
        while(sum<B&&j<A.size()){
            j++;
            sum=sum+A[j];
        }
        count=count+j-i;
    }
    return count;
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
//Sliding Window
int Solution::solve(vector<int> &A, int B) {
    
    int count = 0, sum = 0;
    
    int lo = 0, hi = 0;
  
    while(hi < A.size()){
        
        sum += A[hi];
    
        if(sum < B){
            count += hi - lo + 1;
        }
        else{
            while(sum >= B && lo < hi){
                sum -= A[lo];
                lo++;
            }
            
            if(lo == hi){
                if(A[hi] >= B){
                    lo++;
                    sum = 0;
                }
                else{
                    count += 1;
                }
            }
            else{
                count += hi - lo + 1;
            }
        }
        hi++;
    }
    return count;
}
