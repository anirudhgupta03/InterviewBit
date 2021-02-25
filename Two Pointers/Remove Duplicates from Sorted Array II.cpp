int Solution::removeDuplicates(vector<int> &A) {
    
   int n = A.size();
   if(n <=2){
       return n;
   }
   
   int left = 2;
   
   for(int right = 2; right < A.size(); right++){
       if(A[left-2] != A[right]){
           A[left] = A[right];
           left++;
       }
   }
   
   return left;
}
