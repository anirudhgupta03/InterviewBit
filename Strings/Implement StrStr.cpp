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
