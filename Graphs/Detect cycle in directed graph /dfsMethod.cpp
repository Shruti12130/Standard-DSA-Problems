bool detectCycleByDFS(int i, vector<bool> &vis, vector<bool> &dfsvis, vector<int> adj[]) {
        vis[i] = 1;
        dfsvis[i] = 1;
        
        for(auto it: adj[i]) {
            if(!vis[it]) {
                if(detectCycleByDFS(it, vis, dfsvis, adj)) {
                    return 1;
                }
            } else if(dfsvis[it]) {
                return 1;
            }
        }
        dfsvis[i] = 0;
        return 0;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, 0), dfsvis(V+1, 0);
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(detectCycleByDFS(i, vis, dfsvis, adj)) {
                    return 1;
                }
            }
        }
        return 0;
    }
