int Solution::maxArea(vector<int> &A) {
    
    int max_area = 0;
    
    int a = 0, b = A.size() - 1;
    
    while(a < b)
    {
        if(A[a] < A[b])
        {
            max_area = max(max_area,A[a]*(b-a));
            a++;
        }
        else{
            max_area = max(max_area,A[b]*(b-a));
            b--;
        }
    }
    
    return max_area;
}
