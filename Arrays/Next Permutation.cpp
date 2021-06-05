//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=LuLCLgMElus
//Approach 
// 1) A[i] < A[i+1] ind1 = i (R-L)
// 2) A[ind1] < A[i] ind2 = i (L-R)
// 3) swap(A[ind1],A[ind2])
// 4) reverse(ind1 + 1,last)
vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int ind1 = A.size()-2;
    
    while(A[ind1]>= A[ind1+1] && ind1>=0){
        ind1--;
    }
    
    if(ind1 == -1){
        
        int l = 0, r= A.size()-1;
        while(l<r){
            swap(A[l],A[r]);
            l++;
            r--;
        }
        
        return A;
    }
    
    int ind2;
    
    for(int i = ind1+1; i<A.size(); i++){
        if(A[i] > A[ind1]){
            ind2=i;
        }
        else{
            break;
        }
    }
    swap(A[ind1],A[ind2]);
    int l = ind1+1 , r=A.size()-1;
    while(l<r){
        swap(A[l],A[r]);
        l++;
        r--;
    }
    return A;
}
