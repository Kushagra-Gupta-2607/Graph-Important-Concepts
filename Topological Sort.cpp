// DFS Approach

void check(vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, int node){
    vis[node] = 1;
    
    for(auto next: node){
        if(vis[next] == 0){
            check(adj, vis, ans, next);
        }
    }
    
    ans.push_back(node);
}

vector<int> topoSort(int n, vector<vector<int>>& adj){
    vector<int> ans, vis(n, 0);
    for(int i = 0; i<n; i++){
        if(vis[i] == 0){
            check(adj, vis, ans, i);
        }
    }
    reverse(ans.begin(), ans,end());
    return ans;
}


// BFS Approach (Kahn's Algorithm)

vector<int> topoSort(int n, vector<vector<int>>& adj){
    queue<int> q;
    vector<int> indegree(n, 0), ans;
    
    for(int i = 0; i<n; i++){
        for(auto it: adj[i]) indegree[it]++;
    }
    
    for(int i = 0; i<n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    
    while(q.empty() == false){
        int node = q.fornt();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(--indegree[it] == 0) q.push(it);
        }
    }
    
    return ans;
}
