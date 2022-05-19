//Ref: https://www.interviewbit.com/problems/valid-ip-addresses/discussion/p/c-o-n3-simple/75612/738
//TC - O(N^3)
//SC - O(1)
bool isValid(string &s){
    if(s.size() > 3 || s.size() < 1){
        return false;
    }
    if(s.size() == 2 || s.size() == 3){
        if(s[0] == '0'){
            return false;
        }
        int p = stoi(s);
        if(p < 0 || p > 255){
            return false;
        }
    }
    return true;
}
vector<string> Solution::restoreIpAddresses(string A) {

    int n = A.size();
    vector<string> ans;

    if(n < 4 || n > 12){
        return ans;
    }
    string a, b, c, d;
    for(int i = 0; i < n; i++){
        a = A.substr(0, i + 1);
        if(!isValid(a)) continue;
      
        for(int j = i + 1; j < n; j++){
            b = A.substr(i + 1, j - i);
            if(!isValid(b)) continue;
          
            for(int k = j + 1; k < n; k++){
                c = A.substr(j + 1, k - j);
                d = A.substr(k + 1, A.size() - k);
              
                if(isValid(c) && isValid(d)){
                    ans.push_back(a + "." + b + "." + c + "." + d);
                }
            }
        }
    }
    return ans;
}
