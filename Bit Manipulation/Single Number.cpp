//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::singleNumber(const vector<int> &A) {
    
    int ans = 0;
    
    for(auto  x : A){
        ans ^= x;
    }
    
    return ans;
}
