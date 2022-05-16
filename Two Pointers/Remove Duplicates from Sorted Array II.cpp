//Method - 1
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

//Method - 2
int Solution::removeDuplicates(vector<int> &A) {
    
    if(A.size() == 1){
        return 1;
    }
    int l = 0, r = 1, ele = A[0], count = 1;
    
    while(r < A.size()){
        
        if(A[r] == ele){
            r++;
            count++;
        }
        else{
            if(count >= 2){
                A[l] = ele;
                A[l+1] = ele;
                l = l + 2;
            }
            else{
                A[l] = ele;
                l++;
            }
            count = 1;
            ele = A[r];
            r++;
        }
    }
    if(count >= 2){
        A[l] = ele;
        A[l+1] = ele;
        l = l + 2;
    }
    else{
        A[l] = ele;
        l++;
    }
    return l;
}

//Method - 3
int Solution::removeDuplicates(vector<int> &A) {
    int ptr = 0, i = 0, count = 0;
    while(i < A.size()){
        int ele = A[i];
        while(i < A.size() && A[i] == ele){
            count++;
            i++;
        }
        count = min(count, 2);
        while(count--){
            A[ptr] = ele;
            ptr++;
        }
        count = 0;
    }
    return ptr;
}
