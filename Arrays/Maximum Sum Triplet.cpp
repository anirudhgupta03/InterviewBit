//Brute Force Approach
//Simple Approach is to traverse for every triplet with three nested ‘for loops’ and find update 
//the sum of all triplets one by one. Time complexity of this approach is O(n3) which is not sufficient for a larger value of ‘n’. 
//Time Complexity - O(N^2)
//Space Complexity - O(1)
//Time Limit Exceeded

//Better Approach
//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
//Time Limit Exceeded
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    int ans = INT_MIN;
    
    for(int j = 1; j < n - 1; j++){
        
        int e1 = INT_MIN, e2 = INT_MIN;
        
        for(int i = 0; i < j; i++){
            if(A[i] < A[j]){
                e1 = max(A[i],e1);
            }
        }
        
        for(int k = j + 1; k < n; k++){
            if(A[k] > A[j]){
                e2 = max(A[k],e2);
            }
        }
        
        if(e1 != INT_MIN && e2 != INT_MIN){
            ans = max(ans,e1+e2+A[j]);
        }
    }
    return ans;
}

//Best Approach:
//Ref: https://www.youtube.com/watch?v=l_hPdol4CSU
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
    for(int i=1;i<n-1;i++){         //O(N)
        s.insert(A[i-1]);
        it = s.lower_bound(A[i]);       //O(logN)
        it--;
        if(b[i]>A[i]&&((*it)<A[i])){
            sum = *it + A[i] +b[i];
        }
        ans=max(ans,sum);
    }
    return ans;
}

//Method - 3
int Solution::solve(vector<int> &A) {

    int n = A.size();

    vector<int> maxRight(n);
    maxRight[n - 1] = A[n - 1];

    for(int i = n - 2; i >= 0; i--){
        maxRight[i] = max(maxRight[i + 1], A[i]);
    }

    int maxSum = 0;
    set<int> st;
    st.insert(A[0]);

    for(int i = 1; i < n - 1; i++){
        if(A[i] < maxRight[i + 1]){
            int lo = 0, hi = i - 1, ans = -1;
            auto it = st.lower_bound(A[i]);
            if(it != st.begin()){ 
                it--;
                maxSum = max(maxSum, *it + A[i] + maxRight[i + 1]);
            }
        }
        st.insert(A[i]);
    }
    return maxSum;
}

//Method - 4
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    vector<int> rightMax(n);
    rightMax[n - 1] = A[n - 1];
    
    for(int i = n - 2; i >= 0; i--){
        rightMax[i] = max(rightMax[i + 1], A[i]);
    }
    
    set<int> s;
    s.insert(A[0]);
    
    int maxSum = 0;
    
    for(int i = 1; i < n - 1; i++){
        s.insert(A[i]);
        auto it = s.lower_bound(A[i]);
        if(it == s.begin()) continue;
        
        it--;
        int l = *it, r = rightMax[i + 1];
        
        if(A[i] < r){
            maxSum = max(maxSum, l + A[i] + r);
        }
    }
    return maxSum;
}
