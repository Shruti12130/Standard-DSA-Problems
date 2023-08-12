void dfs(int i, vector<bool> &vis, vector<int> adj[], vector<int> &ans) {
        vis[i] = 1;
        ans.push_back(i);
        
        for(auto it: adj[i]) {
            if(!vis[it]) {
                dfs(it, vis, adj, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V+1, 0);
        dfs(0, vis, adj, ans);
        return ans;
    }
