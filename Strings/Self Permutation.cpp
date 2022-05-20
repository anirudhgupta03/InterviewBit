//Method - 1
int Solution::permuteStrings(string A, string B) {

    if(A.size() != B.size()){
        return 0;
    }
    int alpha1[26] = {0};
    int alpha2[26] = {0};

    for(int i = 0; i < A.size(); i++){
        alpha1[A[i] - 'a']++;
    }
    for(int i = 0; i < B.size(); i++){
        alpha2[B[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(alpha1[i] != alpha2[i]) return 0;
    }
    return 1;
}

//Method - 2
int Solution::permuteStrings(string A, string B) {

    if(A.size() != B.size()){
        return 0;
    }
    int freq[26] = {0};

    for(int i = 0; i < A.size(); i++){
        freq[A[i] - 'a']++;
    }
    for(int i = 0; i < B.size(); i++){
        freq[B[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(freq[i]) return 0;
    }
    return 1;
}
