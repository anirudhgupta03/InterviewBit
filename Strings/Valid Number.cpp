//Brute Force Approach
//Time Complexity - O(N)
//Space Complexity - O(1)
bool isDigit(char c){
    
    if(c >= '0' && c <= '9'){
        return true;
    }
    return false;
}
int Solution::isNumber(const string A) {
    
    int n = A.size();
    
    bool flag1 = false; //operator '+' '-'
    bool flag2 = false; //dot
    bool flag3 = false; //num
    
    for(int i = 0; i < n; i++){
        
        if(isalpha(A[i]) && A[i] != 'e'){
            return 0;
        }
        else if(A[i] == 'e'){
            
            if(i == 0 || i == n - 1 || !isDigit(A[i-1])){
                return 0;
            }
            
            int pos = i;
	    i++;
            
            while(i < n){
                
                if(A[i] == '.'){		//Dot not allowed after 'e'
                    return 0;
                }
                else if(isalpha(A[i])){		//No characters allowed after 'e'
                    return 0;
                }
                else if(A[i] == '+' || A[i] == '-'){	//If there is a '+' or '-' operator it should be next to 'e' and also after that a digit should be there
                 
                    if(i != pos + 1 || i == n - 1 || !isDigit(A[i+1])){
                        return 0;
                    }
                }
                i++;
            }
        }
        else if(A[i] >= '0' && A[i] <= '9'){	
            flag3 = true;
        }
        else if(A[i] == '+' || A[i] == '-'){
            if(flag3 || i == n - 1 || !isDigit(A[i+1])){
                return 0;
            }
            flag1 = true;
        }
        else if(A[i] == '.'){
            if(flag2 || i == n - 1 || !isDigit(A[i+1])){
                return 0;
            }
            flag2 = true;
        }
        else if(A[i] != ' '){
            return 0;
        }
    }
    return flag3;
}

//Optimal Approach
//Time Complexity - O(N)
//Space Complexity - O(1)
//Setting a variable true means it cannot come further now
//Setting a variable false means it can come further
int Solution::isNumber(const string A) {
    
    int len = A.length();
    
    bool sign = false;
    bool num = false;
    bool e = false;
    bool dot = false;
    
    int l = 0, r = A.length() - 1;
    
    while(l <=r && A[l] == ' ')l++;
    while(r >= 0 && A[r] == ' ')r--;

    while(l <= r){
        
        char ch = A[l];
        
        if(isdigit(ch)){
            num = true;
        }
        else if(ch == 'e'){
            if(!num || e){
                return false;
            }
            e = true;	
            num = false;
            sign = false; 
        }
        else if(ch == '+' || ch == '-'){
            if(sign || num){
                return false;
            }
            sign = true;
        }
        else if(ch == '.'){
            if(dot || e){
                return false;
            }
            dot = true;
            sign = true;
            num = false;
        }
        else{
            return false;
        }
        l++;
    }
    return num;
}
