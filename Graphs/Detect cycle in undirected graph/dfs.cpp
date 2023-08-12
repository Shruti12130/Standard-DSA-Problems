bool detetCycleByDFS(int i, int par, vector<bool> vis, vector<int> adj[]) {
        vis[i] = 1;
        for(auto it: adj[i]) {
            if(!vis[it]) {
                if(detetCycleByDFS(it, i, vis, adj)) {
                    return 1;
                }
            } else if (it != par) {
                return 1;
            }
        }
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, 0);
        for(int i=0; i<V; i++) {
            if(detetCycleByDFS(i, -1, vis, adj)) {
                return 1;
            }
        }
        return 0;
    }
