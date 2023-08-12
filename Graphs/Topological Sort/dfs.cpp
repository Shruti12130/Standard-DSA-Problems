void topoSortByDFS(int i, vector<bool> &vis, stack<int> &st, vector<int> adj[]) {
            vis[i] = 1;
            
            for(auto it: adj[i]) {
                if(!vis[it]) {
                    topoSortByDFS(it, vis, st, adj);
                }
            }
            st.push(i);
        }
        
        vector<int> topoSort(int V, vector<int> adj[]) 
        {
            vector<int> ans;
            stack<int> st;
            vector<bool> vis(V+1, 0);
            for(int i=0;i<V;i++) {
                if(!vis[i]) {
                    topoSortByDFS(0, vis, st, adj);
                }
            }
            
            while(!st.empty()) {
                ans.push_back(st.top()); 
                st.pop();
            }
            return ans;
        }
