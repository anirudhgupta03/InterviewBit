// Here we are asked to find subarrays with k distinct integers inside it , 
// so we can approach like subarrays with atmost k integers - subarrays with atmost (k-1) integers . So we will get the Subarrays with exact k integers inside it.
int subarray(vector<int> &A, int B){
    
    int count = 0;
    
    int lo = 0, hi = 0;
    
    unordered_map<int,int> umap;
    
    while(hi < A.size()){
        
        umap[A[hi]]++;
        
        int c = umap.size();
        
        if(c <= B){
            count += hi - lo + 1;
        }
        else{
            while(umap.size() > B && lo < hi){
                
                umap[A[lo]]--;
                if(umap[A[lo]] == 0){
                    umap.erase(A[lo]);
                }
                lo++;
            }
            count += hi - lo + 1;
        }
        hi++;
    }
    return count;
}
int Solution::solve(vector<int> &A, int B) {
    
    if(B == 1){
        return subarray(A,B);
    }
    return subarray(A,B) - subarray(A,B-1);
}

//Alter
int subarray(vector<int> &A, int B){

    unordered_map<int,int> umap;
    
    int count = 0;

    int lo = 0, hi = 0, n;

    while(hi < A.size()){
        
        umap[A[hi]]++;
        
        if(umap.size() > B){
            
            n = hi - lo;
            count += (n*(n+1))/2;
            
            while(umap.size() > B && lo < hi){
                umap[A[lo]]--;
                if(umap[A[lo]] == 0){
                    umap.erase(A[lo]);
                }
                lo++;
            }
            n = hi - lo;
            count -= (n*(n+1))/2;
        }
        hi++;
    }
    n = hi - lo;
    count += (n*(n+1))/2;
    return count;
}
int Solution::solve(vector<int> &A, int B) {

    if(B == 1){
        return subarray(A,B);
    }    
    return subarray(A,B) - subarray(A,B-1);
}
