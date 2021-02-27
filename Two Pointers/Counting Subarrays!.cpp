int Solution::solve(vector<int> &A, int B) {
    int count=0;
    for(int i=0;i<A.size();i++){
        int j=i,sum=A[i];
        while(sum<B&&j<A.size()){
            j++;
            sum=sum+A[j];
        }
        count=count+j-i;
    }
    return count;
}
