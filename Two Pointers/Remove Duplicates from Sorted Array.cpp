int Solution::removeDuplicates(vector<int> &A) {
   
    int l = 1, r = 1;
  
    for(int j = r; j < A.size(); j++)
    {
        if(A[j] != A[j-1])
        {
            A[l] = A[j];
            l++;
        }
    }
    
    return l;
}
