//Method - 1
int myPower(int base, int exponent){
    
    if(exponent == 0) return 1;
    if(exponent == 1) return base;
    
    int temp = myPower(base, exponent/2);
    if(exponent % 2 == 0){
        return temp*temp;
    }
    else{
        return base*temp*temp;
    }
}
int Solution::solve(vector<int> &A, int B, int C) {

    if(A.size() == 0){
        return 0;
    }
    int len = log10(C);
    
    if(B > len + 1){
        return 0;
    }
    else if(B < len + 1){
        int i = 0;
        while(i < A.size() && A[i] == 0){
            i++;
        }
        int ans = (A.size() - i)*myPower(A.size(), B - 1);
        if(B == 1 && A[0] == 0) ans++;
        return ans;
    }
    
    int val = pow(10, len), ans = 0, ind = 0;
    bool flag = false;
    
    if(B == 1 && A[0] == 0){
        ans++;
    }
    
    while(ind != B){
        
        int firstDigit = C/val, count = 0;
        bool exist = false;
        
        for(int i = 0; i < A.size(); i++){
            if(A[i] == firstDigit) exist = true;
            
            if(A[i] < firstDigit){
                if(A[i] || A[i] == 0 && flag){
                    count++;
                }
            }
        }
        ans += count*myPower(A.size(), B - ind - 1);
        
        C %= val;
        val /= 10;
        flag = true;
        if(exist == false) break;
        ind++;
    }   
    return ans;
}

//Method - 2
//Ref: https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
int Solution::solve(vector<int> &A, int B, int C) {

    int n = A.size();

    if(n == 0) return 0;

    int temp = C, count = 0, ans = 0;

    while(temp){
        count++;
        temp /= 10;
    }

    if(count < B){
        return 0;
    }

    if(count > B){
        if(A[0] == 0){
            ans = (n - 1)*pow(n, B - 1);
        }
        else{
            ans = pow(n, B);
        }
        if(B == 1 && A[0] == 0){
            ans++;
        }
        return ans;
    }

    if(B == 1){
        for(int i = 0; i < A.size(); i++){
            if(A[i] < C) ans++;
        }
        return ans;
    }

    vector<int> v(B);

    for(int i = B - 1; i >= 0; i--){
        v[i] = C % 10;
        C /= 10;
    }

    count = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 0) continue;
        if(A[i] > v[0]) break;
        count++;
    }

    ans += (count)*pow(A.size(), B - 1);    //this ans contains extra values

    int j = 0, flag = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == v[0]){
            flag = 1;
        }
    }
    j++;
    while(flag && j <= B - 1){
        flag = 0;
        int countx = 0;
        for(int i = 0; i < A.size(); i++){
            if(A[i] > v[j]){
                countx++;
            }
            if(A[i] == v[j]){
                flag = 1;
            }
        }
        ans -= countx*(pow(A.size(), B - j - 1));
        j++;
    }
    if(j == B && flag == 1) ans--;

    return ans;
}
