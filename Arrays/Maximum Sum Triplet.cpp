//Best Approach:
//Best and efficient approach is use the concept of maximum suffix-array and binary search.

//For finding maximum number greater than given number beyond it, we can maintain a maximum suffix-array array such that for any number(suffix[i]) it would 
//contain maximum number from index i, i+1, … N-1. Suffix array can be calculated in O(N) time.

//For finding maximum number smaller than the given number preceding it, we can maintain a sorted list of numbers before a given number such we can 
//simply perform a binary search to find a number which is just smaller than the given number. In C++ language, we can perform this by using 
//set associative container of STL library.

//Time complexity: O(NlogN)
//Auxiliary space: O(N)

int Solution::solve(vector<int> &A) {
    
    int n=A.size();
    
    int b[n-1];
    b[n-2]=A[n-1];
    for(int i=n-3;i>=0;i--){
        if(A[i+1]>b[i+1]){
            b[i]=A[i+1];
        }
        else{
            b[i]=b[i+1];
        }
    }
    set<int> s;
    set<int> :: iterator it;
    int sum=0,ans=0;
    for(int i=1;i<n-1;i++){
        s.insert(A[i-1]);
        it = s.lower_bound(A[i]);
        it--;
        if(b[i]>A[i]&&((*it)<A[i])){
            sum = *it + A[i] +b[i];
        }
        ans=max(ans,sum);
    }
    return ans;
}
