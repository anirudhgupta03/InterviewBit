vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    int rows = A.size(),columns = A[0].size();
    
    int a[rows] = {0},b[columns] = {0};
    
    int i = 0,j = 0;
    
    vector<int> v;
    
    int count = 0;
    
    while(1){
        
        if(count%2 == 0){
            while(j < columns && b[j] != -1){
                v.push_back(A[i][j]);
                    j++;
            }
            a[i]=-1;
            j--;
            i++;
            while(i < rows && a[i] != -1){
                v.push_back(A[i][j]);
                i++;
            }
            b[j]=-1;
            i--;
            j--;
            count++;
        }
        else{
            while(j >= 0 && b[j] != -1){
                v.push_back(A[i][j]);
                    j--;
            }
            a[i]=-1;
            j++;
            i--;
            while(i >= 0 && a[i] != -1){
                v.push_back(A[i][j]);
                i--;
            }
            b[j]=-1;
            i++;
            j++;
            count++;
        }
        
        if(v.size() == rows*columns){
            break;
        }
    }
    
    return v;
}
