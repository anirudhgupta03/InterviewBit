string Solution::intToRoman(int A) {
    
    string p;
    
    for(int i = 1; i <= A/1000; i++){
        p = p + 'M';
    }
    A %= 1000;
    
    if(A >= 900){
        p = p + "CM";
        A %= 100;
    }
    else{
        for(int i = 1; i <= A/500; i++){
            p = p + 'D';
        }
        A %= 500;
    }
    
    if(A >= 400){
        p = p + "CD";
    }
    else{
        for(int i = 1; i <= A/100; i++){
            p += 'C';
        }
    }
    A %= 100;
    
    if(A >= 90){
        p = p+ "XC";
        A %= 10;
    }
    else{
        for(int i = 1; i <= A/50; i++){
            p += 'L';
        }
        A %= 50;
    }
    
    if(A >= 40){
        p += "XL";
    }
    else{
        for(int i = 1; i <= A/10; i++){
            p += 'X';
        }
    }
    A %= 10;
    
    if(A >= 9){
        p += "IX";
        A %= 1;
    }
    else{
        for(int i = 1; i <= A/5; i++){
            p += 'V';
        }
        A %= 5;
    }
    
    if(A >= 4){
        p += "IV";
    }
    else{
        for(int i = 1; i <= A/1; i++){
            p += 'I';
        }
    }
    A %= 1;
    return p;
}
