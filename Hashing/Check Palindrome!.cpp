int Solution::solve(string A) {
    
    int count[26] = {0};
    
    for(int i = 0; i < A.size(); i++){
        count[A[i] - 97]++;
    }
    
    int n = A.size();
    
    int ev = 0, od = 0;
    
    for(int i = 0; i < 26; i++){
        if(count[i] % 2 == 0){
            ev++;
        }
        else{
            od++;
        }
    }
    
    if(n % 2 == 0){
        if(od != 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(od == 0 || od >= 2){
            return 0;
        }
        else{
            return 1;
        }
    }
}
