int Solution::solve(vector<int> &A, int B, int C) {
    
    if(A.size() == 0){
        return 0;
    }
    int count = 0, temp = C, ans = 0;
    
    while(temp!=0){
        count++;
        temp /= 10;
    }
    
    if(B > count){
        return 0;
    }
    else if(B < count){
        
        if(A[0] == 0){
            ans = (A.size()-1)*pow(A.size(),B-1);
        }
        else{
            ans = pow(A.size(),B);
        }
        if(B == 1 && A[0] == 0){
            ans++;
        }
        return ans;
    }
    else{
        if(B == 1){
            
            for(int i = 0; i < A.size(); i++){
                if(A[i] < C){
                    ans++;
                }
            }
        }
        else{
            
            vector<int> temp(B);
            
            for(int i = B-1; i>=0; i--){
                temp[i] = C%10;
                C /= 10;
            }
            
            count = 0;
            for(auto x : A){
                if(x <= temp[0] && x!=0){
                    count++;
                }
            }
            
            ans = count*pow(A.size(),B-1);
            
            int flag = 0, j = 0;
            for(int i = 0; i < A.size(); i++){
                if(A[i] == temp[0]){
                    flag = 1;
                }
            }
            
            j++;
            while(flag == 1 && j <= B-1){
                flag = 0;
                int countx = 0;
                for(int i = 0 ; i < A.size(); i++){
                    if(A[i] > temp[j]){
                        countx++;
                    }
                    if(A[i] == temp[j]){
                        flag = 1;
                    }
                }
                j++;
                ans -= countx*pow(A.size(),B-j);
            }
            if(j == B && flag == 1){
                ans--;
            }
        }
        return ans;
    }
}
