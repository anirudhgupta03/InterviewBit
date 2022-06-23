//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::bulbs(vector<int> &A) {
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        if(count % 2 == 0 && A[i] == 0 || count % 2 != 0 && A[i] == 1){
            count++;
        }
    }
    return count;
}
