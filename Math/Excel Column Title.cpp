string Solution::convertToTitle(int A) {
    
    string s;
    while(A != 0){
        
        int j = A % 26;
        
        if(j == 0){
            s = s + 'Z';
            A = A/26 -1;
        }
        else{
            
            s = s + (char)(j+64);
            A = A/26;
        }
        
    }
    reverse(s.begin(),s.end());
    return s;
}
