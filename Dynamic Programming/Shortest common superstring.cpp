//MLE
#define pis pair<int,string> 
string overlapShortestString(string &s1, string &s2){
    int i = 0;
    while(i < s1.size()){
        if(s1[i] == s2[0]){
            int ind1 = i, ind2 = 0;
            while(ind1 < s1.size() && ind2 < s2.size()){
                if(s1[ind1] != s2[ind2]){
                    break;
                }
                else{
                    ind1++;
                    ind2++;
                }
            }
            if(ind1 == s1.size()){
                return s1 + s2.substr(ind2, s2.size() - ind2);
            }
            if(ind2 == s2.size()){
                return s1;
            }
        }
        i++;
    }
    return s1 + s2;
}
string rec(int n, vector<string> &words, string temp, int mask, map<pis,string> &dp){

    if(mask == (1 << n) - 1){
        return temp;
    }

    if(dp.find({mask, temp}) != dp.end()){
        return dp[{mask, temp}];
    }

    string res;
    for(int i = 0; i < n; i++){
        if((mask & (1 << i)) == 0){
            string superstring = rec(n, words, words[i], (mask | (1 << i)), dp);
            string appended = overlapShortestString(temp, superstring);
            if(res == "" || appended.size() < res.size()){
                res = appended;
            }
        }
    }
    dp[{mask, temp}] = res;
    return res;
}
int Solution::solve(vector<string> &A) {
    int n = A.size();
    map<pis, string> dp;
    int mask = 0;
    return rec(n, A, "", mask, dp).size();
}
