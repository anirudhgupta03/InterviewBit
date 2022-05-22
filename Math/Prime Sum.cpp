//Method - 1
bool isPrime(int n){

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
vector<int> Solution::primesum(int A) {

    vector<int> res;

    for(int i = 2; i <= A/2; i++){
        if(isPrime(i) && isPrime(A - i)){
            res.push_back(i);
            res.push_back(A - i);
            break;
        }
    }
    return res;
}

//Method - 2
//Using Sieve Of Eratosthenes
vector<int> Solution::primesum(int A) {

    vector<bool> isPrime(A + 1, true);    //Taking interger array gives MLE
    isPrime[1] = false;

    for(int i = 2; i * i <= A; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= A; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= A/2; i++){
        if(isPrime[i] && isPrime[A - i]){
            vector<int> res = {i, A - i};
            return res;
        }
    }
}
