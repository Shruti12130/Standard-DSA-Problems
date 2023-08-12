bool detetCycleByBFS(int i, vector<bool> vis, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = 1;
        
        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it: adj[node]) {
                if(!vis[it]) { 
                    vis[it] = 1;
                    q.push({it, node});
                } else if (it != par) { 
                    return 1;
                }
            }
        }
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, 0);
        for(int i=0; i<V; i++) {
            if(detetCycleByBFS(i, vis, adj)) {
                return 1;
            }
        }
        return 0;
    }
