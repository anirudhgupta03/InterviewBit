//Method - 1
//Method - 2
vector<int> Solution::flip(string A) {

    int l = -1, r = -1, currsum = 0, maxsum = 0, tl = 0;

    for(int i = 0; i < A.size(); i++){

        if(A[i] == '0') currsum++;
        else currsum--;

        if(currsum > maxsum){
            maxsum = currsum;
            l = tl;
            r = i;
        }

        if(currsum < 0){
            currsum = 0;
            tl = i + 1;
        }
    }
    vector<int> res;
    if(l != -1 && r != -1){
        res.push_back(l + 1);
        res.push_back(r + 1);
    }
    return res;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=cLVpE5q_-DE
//Time Complexity - O(N)
//Space Complexity - O(1)
//Kadane's Algorithm
vector<int> Solution::flip(string A) {
    
    int count = 0, l, r, max_count = 0, ltemp = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '1'){
            count++;
        }
    }
    
    if(count == A.size()){
        vector<int> res;
        return res;
    }
    
    count = 0;
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == '0'){
            count++;
        }
        else{
            count--;
        }

        if(count > max_count){
            max_count = count;
            l = ltemp;
            r = i;
        }
        
        if(count < 0){
            count = 0;
            ltemp = i + 1;
        }
    }
    vector<int> res = {l+1,r+1};
    return res;
}
