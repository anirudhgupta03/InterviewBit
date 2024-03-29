//Brute Force Approach
//Time Complexity - O(N)
//Space Complexity - O(N)
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    int hash[A.size()+1] = {0};
    
    for(int i = 0; i < A.size(); i++){
        hash[A[i]]++;
    }
    int miss,repeat;
    for(int i = 1; i < A.size()+1; i++){
        if(hash[i]==0){
            miss = i;
        }
        else if(hash[i]==2){
            repeat = i;
        }
    }
    vector<int> v;
    v.push_back(repeat);
    v.push_back(miss);
    return v;
}

//Better Approach
//Time Complexity - O(N)
//Space Complexity - O(N)
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    int arr[A.size()];
    
    for(int i = 0; i < A.size(); i++){
        arr[i] = A[i];
    }
    
    int miss, repeat;
    for(int i = 0; i < A.size(); i++){
        
        int j = abs(arr[i])-1;
        if(arr[j] < 0){
            repeat = j+1;
        }
        arr[j] = -abs(arr[j]);
    }
    
    for(int i = 0; i < A.size(); i++){
        
        if(arr[i] > 0){
            miss = i+1;
        }
    }
    
    vector<int> v;
    v.push_back(repeat);
    v.push_back(miss);
    
    return v;
}

//Optimal Approach
//Time Complexity - O(N)
//Space Complexity - O(1)

// Sum(Actual) = Sum(1...N) + A - B

// Sum(Actual) - Sum(1...N) = A - B. 

// Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2

// Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) = (Sum(Actual) - Sum(1...N)) ( A + B). 

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    long long sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < A.size(); i++){
        sum1 = sum1 + (long long)A[i];
        sum2 = sum2 + ((long long)A[i]*(long long)A[i]);
    }
    long long n = A.size();
    long long sum3 = (n*(n+1))/2;
    long long sum4 = (n*(n+1)*(2*n+1))/6;
    
    long long x = sum3-sum1;
    long long y = sum4-sum2;
    long long z;
    
    z = y/x;
    
    int r = (z-x)/2;
    int s = (z+x)/2;
    vector<int> v;
    v.push_back(r);
    v.push_back(s);
    return v;
    
}   

//Optimal Approach 2
#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &A) {

    ll n = A.size();
    ll sumofn1 = 0, sumofn2 = 0;
    ll sumofsquares1 = 0, sumofsquares2 = 0;
    
    for(ll i = 1; i <= n; i++){
        sumofn1 += i;
        sumofsquares1 += i*i;
    }

    for(ll x: A){
        sumofn2 += x;
        sumofsquares2 += x*x;
    }
    vector<int> res;
    
    ll diff = sumofn1 - sumofn2;

    ll temp = sumofsquares1 - sumofsquares2;

    ll summation = temp/diff;

    ll repeat = (summation - diff)/2;
    ll miss = (summation + diff)/2;
    res.push_back(repeat);
    res.push_back(miss);

    return res;
}

//Optimal Approach 3
#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    ll diff1 = 0;
    
    for(ll i = 0; i < A.size(); i++){
        diff1 += (i + 1 - A[i]);
    }
    
    ll diff2 = 0;
    
    for(ll i = 0; i < A.size(); i++){
        diff2 += ((i + 1)*(i + 1) - (ll)A[i]*A[i]);
    }
    
    ll sum = diff2/diff1;
    
    ll repeat = (sum - diff1)/2;
    ll miss = sum - repeat;
    vector<int> res = {repeat, miss};
    return res; 
}
