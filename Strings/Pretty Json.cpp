vector<string> Solution::prettyJSON(string s) {

    vector<string> res;
    int indent = 0;
    char last;
    string ans = "";

    for(auto ch:s){
        if(ch==' ')
            continue;
        
        if(ch=='}' ||ch==']' )
            indent--;
        
        if(last=='[' ||  last == '{' || ch==']' || ch == '}' || last == ',' || (last==':' && (ch=='{' || ch=='['))){
            res.push_back(ans);
            ans="";
            for(int i=1;i<=indent;i++){
                ans+="\t";
            }
        }
        
        if(ch=='[' || ch=='{')
            indent++;
        ans += ch;
        last = ch;
    }
    if(ans!="") res.push_back(ans);
    return res;
}
