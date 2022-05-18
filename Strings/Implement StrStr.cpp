//Rabin Karp Search Algo
//Time Complexity - https://cp-algorithms.com/string/rabin-karp.html#:~:text=This%20will%20take%20a%20total,%7Cs%7C%20with%20the%20pattern.
#define  ll long long
ll findHash(string s){
    
    ll sum = 0;
    
    for(int i = 0; i < s.size(); i++){
        sum += (s[i] - 'a' + 1)*(pow(3,i));
    }
    return sum;
}
int Solution::strStr(const string A, const string B) {
    
    if(A.size() < B.size()){
        return -1;
    }
    
    ll hash1 = findHash(B);
    
    ll hash2 = findHash(A.substr(0,B.size()));
    
    if(hash1 == hash2){
        if(A.substr(0,B.size()) == B){
            return 0;
        }
    }
    
    for(int i = 1; i <= A.size() - B.size(); i++){
        
        hash2 -= (A[i-1] - 'a' + 1);
        hash2 /= 3;
        hash2 += (A[i+B.size()-1] - 'a' + 1)*pow(3,B.size()-1);
        
        if(hash2 == hash1){
            if(B == A.substr(i,B.size()))
            return i;
        }
    }
    return -1;
}

//KMP String Matching Algo
//TC - O(n)
//SC - O(n)
int Solution::strStr(const string A, const string B) {

    if(A.size() == 0 || B.size() == 0){
        return -1;
    }
    if(B.size() > A.size()){
        return -1;
    }
    int n = B.size();

    vector<int> lps(n);

    lps[0] = 0;

    int j = 0, i = 1;

    while(i < n){
        if(B[i] == B[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }
        else{
            if(j != 0) {
                j = lps[j - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    
    i = 0, j = 0;

    while(i < A.size() && j < B.size()){
        if(A[i] == B[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    if(j == B.size()){
        return i - B.size();
    }
    return -1;
}
