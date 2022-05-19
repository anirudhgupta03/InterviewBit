string Solution::intToRoman(int A) {
    
    string p;
    
    for(int i = 1; i <= A/1000; i++){
        p += 'M';
    }
    A %= 1000;
    
    if(A / 100 == 9){
        p += "CM";
    }
    else if(A / 100 == 4){
        p += "CD";   
    }
    else{
        for(int i = 1; i <= A/500; i++){
            p += 'D';
        }
        A %= 500;
        for(int i = 1; i <= A/100; i++){
            p += 'C';
        }
    }
    A %= 100;
    
    if(A / 10 == 9){
        p += "XC";
    }
    else if(A / 10 == 4){
        p += "XL";
    }
    else{
        for(int i = 1; i <= A/50; i++){
            p += 'L';
        }
        A %= 50;
        for(int i = 1; i <= A/10; i++){
            p += 'X';
        }
    }
    A %= 10;
    
    if(A == 9){
        p += "IX";
    }
    else if(A == 4){
        p += "IV";
    }
    else{
        for(int i = 1; i <= A/5; i++){
            p += 'V';
        }
        A %= 5;
        for(int i = 1; i <= A; i++){
            p += 'I';
        }
    }
    A %= 1;
    return p;
}
