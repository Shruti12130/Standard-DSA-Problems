vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        vector<int> minPath(n, INT_MAX);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;   
        q.push(src);    
        minPath[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                if(minPath[node] + 1 < minPath[it]) {
                    minPath[it] = minPath[node] + 1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++) {
            minPath[i] = (minPath[i]==INT_MAX) ? -1 : minPath[i];
        }
        return minPath;
    }
