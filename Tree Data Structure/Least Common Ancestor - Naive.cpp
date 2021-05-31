/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, vector<int> &path, vector<int> temp, int key){
    
    if(A == NULL){
        return;
    }
    
    temp.push_back(A -> val);
    if(A -> val == key){
        path = temp;
        return;
    }
    
    solve(A->left,path,temp,key);
    solve(A->right,path,temp,key);
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    vector<int> path1,path2;
    
    vector<int> temp;
    
    solve(A,path1,temp,B);
    solve(A,path2,temp,C);
    
    if(find(path1.begin(),path1.end(),B) == path1.end()){
        return -1;
    }
    if(find(path2.begin(),path2.end(),C) == path2.end()){
        return -1;
    }
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < path1.size(); i++){
        umap[path1[i]]++;
    }
    
    for(int i = path2.size() - 1; i >= 0; i--){
        if(umap.find(path2[i]) != umap.end()){
            return path2[i];
        }
    }
}
