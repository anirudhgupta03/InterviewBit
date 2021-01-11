/*
f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways 
(Since we are looking at max value, we don’t even care if the value becomes negative as long as we are also covering the max value in some way).

(A[i] + i) - (A[j] + j)
-(A[i] - i) + (A[j] - j) 
(A[i] - i) - (A[j] - j) 
(-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
Note that case 1 and 4 are equivalent and so are case 2 and 3.

We can construct two arrays with values: A[i] + i and A[i] - i. 
Then, for above 2 cases, we find the maximum value possible. For that, we just have to store minimum and maximum values of expressions A[i] + i and A[i] - i for all i.
*/

int Solution::maxArr(vector<int> &A) {
    
    int n=A.size();
    
    int a[n],b[n];
    
    for(int i = 0; i < n; i++){
        a[i]=A[i]+i;
    }
    
    for(int i = 0; i < n; i++){
        b[i]=A[i]-i;
    }
    
    int max1 = a[0],min1 = a[0],max2 = b[0],min2 = b[0];
    
    for(int i = 1; i < n; i++){
        if(a[i] > max1){
            max1 = a[i];
        }
        else if(a[i] < min1){
            min1 = a[i];
        }
    }
    
    for(int i = 1; i < n; i++){
        if(b[i] > max2){
            max2 = b[i];
        }
        else if(b[i] < min2){
            min2 = b[i];
        }
    }
    return max(max1-min1,max2-min2);
}
