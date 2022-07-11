//Method - 1
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

//Method - 2
vector<string> Solution::prettyJSON(string A) {
    
    vector<string> v;
    int shift = 0;
    string temp;
    bool flag = false;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '}' || A[i] == ']'){
            flag = false;
            if(temp.size()){
                v.push_back(temp);
            }
            temp.clear();
            string s;
            shift--;
            for(int j = 0; j < shift; j++){
                s.push_back('\t');
            }
            s.push_back(A[i]);
            if(i < A.size() - 1 && A[i + 1] == ','){
                s.push_back(',');
                i++;
            }
            v.push_back(s);
        }
        else if(A[i] == '{' || A[i] == '['){
            if(temp.size()){
                v.push_back(temp);
            }
            temp.clear();
            flag = false;
            string s;
            for(int j = 0; j < shift; j++){
                s.push_back('\t');
            }
            s.push_back(A[i]);
            v.push_back(s);
            shift++;
        }
        else if(A[i] == ','){
            flag = false;
            temp.push_back(',');
            v.push_back(temp);
            temp.clear();
        }
        else{
            if(flag == false){
                for(int j = 0; j < shift; j++){
                    temp.push_back('\t');
                }   
                flag = true;
            }
            temp.push_back(A[i]);
        }
    }
    return v;
}
