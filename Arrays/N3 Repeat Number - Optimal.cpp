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
