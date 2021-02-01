int Solution::solve(vector<string> &A) {
    
    vector<float> v;
    
    for(int i = 0; i < A.size(); i++){
        v.push_back(stof(A[i]));
    }
    
    float a = v[0], b = v[1], c = v[2];
    
    for(int i = 3; i < v.size(); i++){
        
        if(a+b+c > 1 && a+b+c <2){
            return 1;
        }
        
        else if(a+b+c >= 2){
            
            if(a >b && a>c){
                a = v[i];
            }
            else if(b > a && b >c){
                b = v[i];
            }
            else if(c >a && c>b){
                c = v[i];
            }
        }
        
        else if(a+b+c <= 1){
            
            if(a < b && a<c){
                a = v[i];
            }
            else if(b < c && b < a){
                b = v[i];
            }
            else if(c<a && c < b){
                c = v[i];
            }
        }
    }
    
    if(a+b+c > 1 && a+b+c < 2)
        return 1;
        
        return 0;
}
