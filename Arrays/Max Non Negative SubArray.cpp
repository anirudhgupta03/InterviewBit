//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(N)
vector<int> Solution::maxset(vector<int> &A) {
    
    vector<int> v1,v2;
    
    long long curr_sum=0,max_sum=0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] < 0){
            curr_sum = 0;
            v2.clear();
            continue;
        }
        
        curr_sum = curr_sum+A[i];
        v2.push_back(A[i]);
        
        if(curr_sum == max_sum){
            if(v2.size()>v1.size()){
                v1.clear();
                    for(int j = 0; j <v2.size(); j++){
                        v1.push_back(v2[j]);
                    }
            }
        }
        else if(curr_sum>max_sum ){
            max_sum=curr_sum;
            v1.clear();
            for(int j = 0; j<v2.size(); j++){
                v1.push_back(v2[j]);
            }
        }
    }
    
    return v1;
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
//Kadane's Algorithm
#define ll long long
vector<int> Solution::maxset(vector<int> &A) {
    
    ll l = 0, r = 0;
    
    ll start = 0, maxLen = 0, currSum = 0, maxSum = 0;
    
    while(r < A.size()){
        
        if(A[r] >= 0){
            currSum += A[r];
        }
        else{
            if(currSum > maxSum){
                maxSum = currSum;
                start = l;
                maxLen = r - l;
            }
            else if(currSum == maxSum && (r-l) > maxLen){
                maxLen = r - l;
                start = l;
            }
            currSum = 0;
            l = r + 1;
        }
        r++;
    }
    if(currSum > maxSum){
        maxSum = currSum;
        start = l;
        maxLen = r - l;
    }
    else if(currSum == maxSum && (r-l) > maxLen){
        maxLen = (r-l);
        start = l;
    }
    
    vector<int> res;
    for(int i = start; i < start + maxLen; i++){
        res.push_back(A[i]);
    }
    
    return res;
}
