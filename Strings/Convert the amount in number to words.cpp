int Solution::solve(string A, string B) {

    unordered_map<int, string> umap;
    
    umap[1] = "one";
    umap[2] = "two";
    umap[3] = "three";
    umap[4] = "four";
    umap[5] = "five";
    umap[6] = "six";
    umap[7] = "seven";
    umap[8] = "eight";
    umap[9] = "nine";
    umap[10] = "ten";
    umap[11] = "eleven";
    umap[12] = "twelve";
    umap[13] = "thirteen";
    umap[14] = "fourteen";
    umap[15] = "fifteen";
    umap[16] = "sixteen";
    umap[17] = "seventeen";
    umap[18] = "eighteen";
    umap[19] = "nineteen";
    umap[20] = "twenty";
    umap[30] = "thirty";
    umap[40] = "forty";
    umap[50] = "fifty";
    umap[60] = "sixty";
    umap[70] = "seventy";
    umap[80] = "eighty";
    umap[90] = "ninety";
    umap[100] = "hundred";
    umap[1000] = "thousand";
    umap[100000] = "lakh";
    umap[10000000] = "crore";
    umap[1000000000] = "arab";

    int n = A.size();

    if(n == 1){
        if(umap[A[0] - '0'] == B){
            return 1;
        }
        return 0;
    }
    int temp = pow(10, n - 1);

    string res;
    int val;
    for(int i = 0; i < n - 2; i++){
        if(umap.find(temp) != umap.end()){
            val = A[i] - '0';
            if(val){
                res += umap[val];
                res.push_back('-');
                res += umap[temp];
                res.push_back('-');
            }
        }
        else{
            val = 10*(A[i] - '0') + A[i + 1] - '0';
            temp /= 10;
            if(val > 0 && val <= 19){
                res += umap[val];
                res.push_back('-');
                res += umap[temp];
                res.push_back('-');
            } 
            else if(val >= 20){
                res += umap[(val/10)*10];
                val %= 10;
                if(val){
                    res.push_back('-');
                    res += umap[val];
                }
                res.push_back('-');
                res += umap[temp];
                res.push_back('-');
            }
            i++;
        }
        temp /= 10;
    }

    val = 10*(A[n - 2] - '0') + A[n- 1] - '0';
    if(val > 0 && val <= 19){
        if(res.size()){
            res += "and";
            res.push_back('-');
        }
        res += umap[val];
    } 
    else if(val >= 20){
        if(res.size()){
            res += "and";
            res.push_back('-');
        }
        res += umap[(val/10)*10];
        val %= 10;
        if(val){
            res.push_back('-');
            res += umap[val];
        }
    }
    else{
        res.pop_back();
    }
//     cout << res << endl;
    if(res == B) return 1;
    return 0;
}
