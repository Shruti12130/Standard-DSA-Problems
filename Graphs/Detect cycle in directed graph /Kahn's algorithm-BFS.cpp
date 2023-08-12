//Kahn's Algorithm
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indeg(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]) {
                indeg[it]--;
                if(indeg[it]==0) {
                    q.push(it);
                }
            }
        }
        if(cnt == V) {
            return 0;
        }
        return 1;
    }
