int Solution::solve(string A, int B) {

    int start = 1;
    if(A == "Monday"){
        start += 6;
    }
    if(A == "Tuesday"){
        start += 5;
    }
    if(A == "Wednesday"){
        start += 4;
    }
    if(A == "Thursday"){
        start += 3;
    }
    if(A == "Friday"){
        start += 2;
    }
    if(A == "Saturday"){
        start += 1;
    }

    if(B >= start){
        return (B - start)/7 + 1;
    }
    else{
        return 0;
    }
}
