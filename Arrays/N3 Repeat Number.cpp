//Method - 1
int Solution::repeatedNumber(const vector<int> &A) {
    
    int n = A.size();

    if(n == 1){
        return A[0];
    }

    int ele1, ele2, count1 = 0, count2 = 0;

    for(int i = 0; i < n; i++){

        if(count1 == 0){
            ele1 = A[i];
            count1 = 1;
        }
        else if(A[i] == ele1){
            count1++;
        }
        else if(count2 == 0){
            ele2 = A[i];
            count2 = 1;
        }
        else if(A[i] == ele2){
            count2++;
        }
        else if(count1 == 1){
            ele1 = A[i];
        }
        else if(count2 == 1){
            ele2 = A[i];
        }
        else{
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for(int i = 0; i < n; i++){
        if(A[i] == ele1){
            count1++;
        }
        else if(A[i] == ele2){
            count2++;
        }
    }
    if(count1 > n/3) return ele1;
    if(count2 > n/3) return ele2;
    return -1;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=yDbkQd9t2ig
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::repeatedNumber(const vector<int> &A) {
    
    int ele1 = -1 , ele2= -1, count1 = 0,count2 =0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(ele1 == A[i]){
            count1++;
        }
        else if(ele2 == A[i]){
            count2++;
        }
        else if(count1 == 0){
            ele1 = A[i];
            count1++;
        }
        else if(count2 == 0){
            ele2 = A[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    int cnt1 = 0,cnt2=0;
    for(int i = 0; i < A.size(); i++){
        if(ele1 == A[i]){
            cnt1++;
        }
        else if(ele2 == A[i]){
            cnt2++;
        }
    }
    if(cnt1 >  A.size()/3){
        return ele1;
    }
    else if(cnt2 > A.size()/3){
        return ele2;
    }
    
    return -1;
}
