//Method - 1
//TC - O(N)
//SC - O(N)
vector<int> Solution::solve(vector<int> &A) {

    vector<int> pos, neg;

    for(int i = 0; i < A.size(); i++){
        if(A[i] < 0){
            neg.push_back(A[i]*A[i]);
        }
        else{
            pos.push_back(A[i]*A[i]);
        }
    }

    vector<int> res;
    
    int ptr1 = 0, ptr2 = neg.size() - 1;

    while(ptr1 < pos.size() && ptr2 >= 0){
        if(pos[ptr1] < neg[ptr2]){
            res.push_back(pos[ptr1]);
            ptr1++;
        }
        else{
            res.push_back(neg[ptr2]);
            ptr2--;
        }
    }
    while(ptr1 < pos.size()){
        res.push_back(pos[ptr1]);
        ptr1++;
    }
    while(ptr2 >= 0){
        res.push_back(neg[ptr2]);
        ptr2--;
    }
    return res;
}


//Method - 2
//TC - O(N)
//SC - O(1)
vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> ans(A.size());
    
    int i=0,j = A.size()-1 , k = A.size()-1;
    
    while(i<=j){
        
        if(abs(A[i])>abs(A[j])){
            ans[k] = A[i]*A[i];
            i++;
            k--;
        }
        else{
            ans[k] = A[j]*A[j];
            j--;
            k--;
        }
    }
    
    return ans;
}
