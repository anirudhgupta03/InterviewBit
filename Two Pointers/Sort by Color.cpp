//Method - 1
//Time Complexity - O(2*N)
//Space Complexity - O(1)
void Solution::sortColors(vector<int> &A) {
    
    int count1 = 0, count2 = 0;
    
    for(auto x : A){
        if(x == 0){
            count1++;
        }
        else if(x == 1){
            count2++;
        }
    }
    
    for(int i = 0; i < count1; i++){
        A[i] = 0;
    }
    for(int i = count1; i < count1 + count2; i++){
        A[i] = 1;
    }
    for(int i = count1 + count2; i < A.size(); i++){
        A[i] = 2;
    }
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=oaVa-9wmpns
//Dutch National Flag Algorithm
void Solution::sortColors(vector<int> &A) {
    
    int lo = 0, mid = 0, hi = A.size() - 1;
    
    while(mid <= hi){
        
        if(A[mid] == 0){
            swap(A[lo],A[mid]);
            lo++;
            mid++;
        }
        else if(A[mid] == 1){
            mid++;
        }
        else{
            swap(A[mid],A[hi]);
            hi--;
        }
    }
}
