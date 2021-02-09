int paths(int x, int y, int a, int b){
    
    if(x == a && y == b){
        return 1;
    }
    else if(x == a + 1|| y == b + 1){
        return 0;
    }
    return paths(x,y+1,a,b)+paths(x+1,y,a,b);
}
 
int Solution::uniquePaths(int A, int B) {
    
    return paths(0,0,A-1,B-1);
}
