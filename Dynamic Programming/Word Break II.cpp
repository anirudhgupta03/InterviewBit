//Method - 1
vector<string> Solution::wordBreak(string A, vector<string> &B) {

    unordered_map<string,int> umap;

    for(int i = 0; i < B.size(); i++){
        umap[B[i]]++;
    }

    int n = A.size();

    int dp1[n+1];
    
    memset(dp1,0,sizeof(dp1));

    dp1[0] = 1;
    
    vector<vector<string>> dp2(n+1);
    
    dp2[0].push_back("");

    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            
            string s = A.substr(j,i-j);
            
            if(umap.find(s) != umap.end()){
                if(dp1[j]){
                    
                    for(int k = 0; k < dp2[j].size(); k++){
                        string t = dp2[j][k];
                        if(t == "") dp2[i].push_back(s);
                        else        dp2[i].push_back(dp2[j][k] + " " + s);
                    }
                    dp1[i] = 1;
                }
            }
        }
    }
    vector<string> res;
    
    for(int j = 0; j < dp2[n].size(); j++){
        res.push_back(dp2[n][j]);
    }
    sort(res.begin(),res.end());
    return res;
}

//Method - 2
vector<string> Solution::wordBreak(string A, vector<string> &B) {

    unordered_map<string,int> dict;

    for(int i = 0; i < B.size(); i++){
        dict[B[i]]++;
    }

    vector<string> res;
    int n = A.size();
    int dp1[n];

    memset(dp1,0,sizeof(dp1));
    vector<string> dp2[n];

    for(int i = 0; i < n; i++){
        for(int j = i; j >= 0; j--){

            string temp = A.substr(j,i-j+1);

            if(dict.find(temp) != dict.end()){
                
                if(j >= 1){
                    if(dp1[j-1]){
                        dp1[i] += dp1[j-1];
                        vector<string> v = dp2[j-1];

                        for(int k = 0; k < v.size(); k++){
                            dp2[i].push_back(v[k] + " " + temp);
                        }
                    }
                    else{
                        continue;
                    }
                }
                else{
                    dp1[i] = 1;
                    dp2[i].push_back(temp);
                }
            }
        }
    }

    if(dp1[n-1]){
        res = dp2[n - 1];
    }
    sort(res.begin(),res.end());
    return res;
}
