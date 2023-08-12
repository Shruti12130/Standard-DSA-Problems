vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, S});
        vector<int> ans(V, INT_MAX);
        ans[S]=0;
        
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                if(dist + it[1] < ans[it[0]]) {
                    ans[it[0]] = dist + it[1];
                    pq.push({ans[it[0]], it[0]});
                }
            }
        }
        return ans;
    }
