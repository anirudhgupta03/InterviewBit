//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
//Ref: https://www.youtube.com/watch?v=-hOKIfAcwzk
int Solution::solve(int A, vector<int> &B) {
    
    int n = B.size();
    long long prefix[n];
    prefix[0] = B[0];
    
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + B[i];
    }
    
    long long sum = prefix[n-1];
    
    if(sum % 3!=0){
        return 0;
    }
    
    int ans = 0, count = 0;
    
    for(int i=0; i < n-1;i++){
        
        if(3*prefix[i] == 2*sum){         //After we have got the first partition
             ans = ans + count;           //now we calculate the number of second partitions
        }                                 //corresponding to each first partition
                                              
        if(3*prefix[i] == sum ){          //Using this condition we are keeping the
                count++;                  //record of the number of first partitions
            
        }
    }
    return ans;
}

//Method - 2
//TC - O(N)
//SC - O(1)
int Solution::solve(int A, vector<int> &B) {

    int sum = 0;

    for(int i = 0; i < A; i++){
        sum += B[i];
    }

    if(A < 3 || sum % 3 != 0){
        return 0;
    }

    int count = 0, ans = 0, currsum = 0;

    for(int i = 0; i < A - 1; i++){
        currsum += B[i];
        if(currsum == (2*sum)/3) ans += count;
        if(currsum == sum/3) count++;
    }
    return ans;
}
