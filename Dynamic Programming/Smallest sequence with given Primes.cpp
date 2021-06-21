//Ref: https://www.youtube.com/watch?v=rRn1vBH-L-8
#define ll long long
vector<int> Solution::solve(int A, int B, int C, int D) {
    
    int arr[3] = {A,B,C};
    
    sort(arr,arr+3);
    
    vector<int> dp;
    
    if(D == 0){
        return dp;
    }
    dp.push_back(1);
    
    int i = 0, j = 0, k = 0;
    
    while(1){
        
        int a = dp[i]*A;
        int b = dp[j]*B;
        int c = dp[k]*C;
        
        int mine = min(a,min(b,c));
        
        dp.push_back(mine);
        
        if(mine == a){
            i++;
        }
        if(mine == b){
            j++;
        }
        if(mine == c){
            k++;
        }
        
        if(dp.size() == D + 1){
            break;
        }
    }
    
    dp.erase(dp.begin());
    return dp;
}
