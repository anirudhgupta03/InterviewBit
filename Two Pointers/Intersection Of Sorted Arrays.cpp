vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    
    vector<int> ans;
    
    int p1 = 0, p2 = 0;
    
    while(true){
        
        if(p1 == A.size() || p2 == B.size()){
            break;
        }
        
        if(A[p1] < B[p2]){
            p1++;
        }
        else if(A[p1] > B[p2]){
            p2++;
        }
        else if(A[p1] == B[p2]){
            ans.push_back(A[p1]);
            p1++;
            p2++;
        }
    }
    return ans;
}
