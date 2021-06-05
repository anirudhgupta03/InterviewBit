//Method - 1
//Gives lexicographically smallest number
//Ref: https://www.youtube.com/watch?v=BPqE8FomgZ0
vector<int> Solution::findPerm(const string A, int B) {
    
    int end = 0, start = 1;
    
    vector<int> ans;
    
    for(int i = 0; i < A.size(); i++){
        end++;
        if(A[i] == 'I'){
            for(int j = end; j >= start; j--){
                ans.push_back(j);
            }
            start = end+1;
        }
    }
    end++;
    for(int j = end; j >= start; j--){
                ans.push_back(j);
    }
    return ans;
}
//Method - 2
//Optimal Approach
//Time Complexity - O(N)
//Space Complexity - O(1)
vector<int> Solution::findPerm(const string A, int B) {
    
    int a = 1, b= B;
    
    vector<int> ans;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == 'D'){
            ans.push_back(b);
            b--;
        }
        else{
            ans.push_back(a);
            a++;
        }
        
    }
    ans.push_back(a);
    return ans;
}
