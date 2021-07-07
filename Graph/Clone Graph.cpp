//Using DFS
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void dfs(UndirectedGraphNode* curr, UndirectedGraphNode* node, unordered_map<int,UndirectedGraphNode*> &vis){
 
    vis[node->label] = node;
 
    for(auto ele: curr -> neighbors){
        if(vis[ele -> label] == NULL){
            UndirectedGraphNode* newnode = new UndirectedGraphNode(ele->label);
            (node->neighbors).push_back(newnode);
            dfs(ele,newnode,vis);
        }
        else{
            (node->neighbors).push_back(vis[ele->label]);
        }
    }
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    if(node == NULL){
        return NULL;
    }
 
    unordered_map<int,UndirectedGraphNode*> vis;
    
    UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
    vis[node->label] = copy;
 
    for(auto curr: node -> neighbors){
 
        if(vis[curr -> label] == NULL){
            UndirectedGraphNode* temp = new UndirectedGraphNode(curr->label);
            (copy->neighbors).push_back(temp);
            dfs(curr,temp,vis);
        }
        else{
            (copy->neighbors).push_back(vis[curr->label]);
        }
    }
    return copy;
}

//Using BFS
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    if(node == NULL){
        return NULL;
    }
    
    map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    
    UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
    m[node] = copy;
    
    while(!q.empty()){
        UndirectedGraphNode* curr = q.front();
        q.pop();
        int n = curr -> neighbors.size();
        
        for(int i = 0; i < n; i++){
            UndirectedGraphNode* neighbor = curr -> neighbors[i];
            
            if(m.find(neighbor) == m.end()){
                UndirectedGraphNode* p = new UndirectedGraphNode(neighbor->label);
                m[curr]->neighbors.push_back(p);
                m[neighbor] = p;
                q.push(neighbor);
            }
            else{
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
    }
    
    return copy;
}
