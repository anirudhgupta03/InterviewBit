//Gives lexicographically smallest number 

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
