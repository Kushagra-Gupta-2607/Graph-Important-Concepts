// Problem Link:
// Leetcode 785. Is Graph Bipartite?: https://leetcode.com/problems/is-graph-bipartite/

// DFS
class Solution {
public:
    bool notBipartite(vector<vector<int>>& graph, vector<int>& vis, int node){
        for(int x: graph[node]){
            if(vis[x] == -1){
                vis[x] = vis[node]^1;
                if(notBipartite(graph, vis, x)) return true;
            }
            else if(vis[x] == vis[node]) return true;
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i<n; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(notBipartite(graph, vis, i)) return false;
            }
        }
        return true;
    }
};


// BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i<n; i++){
            if(vis[i] == -1){
                queue<int> q;
                vis[i] = 0;
                q.push(i);
                while(q.empty() == false){
                    int curr = q.front();
                    q.pop();
                    for(int node: graph[curr]){
                        if(vis[node] == -1){
                            vis[node] = vis[curr]^1;
                            q.push(node);
                        }
                        else if(vis[node] == vis[curr]) return false;
                    }
                }
            }
        }
        return true;
    }
};
