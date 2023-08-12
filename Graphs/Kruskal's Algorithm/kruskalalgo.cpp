class disjoint{
    vector<int> parent, rank;
    public: 
    disjoint(int n) {
        parent.resize(n+1);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) {
            //Initially every node is an independent component and
            //hence every node is its own parent
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if(parent[node] == node) {
            return node;
        }
        //Path Compression
        return parent[node] = findPar(parent[node]);
    }
    void Union(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        //Small rank node gets attached to the larger rank node
        if(u==v) {
            return;
        }
        if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[u] > rank[v]) {
            parent[v]  =u;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
};

class Solution
{
        public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<V;i++) {
            for(auto it: adj[i]) {
                int u=i;
                int v=it[0];
                int weight = it[1];
                edges.push_back({weight, {u, v}});
            }
        }
        sort(edges.begin(), edges.end());
        disjoint ds(V);
        int cost=0;
        for(auto it: edges) {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.findPar(u) != ds.findPar(v)) {
                cost+=wt;
                ds.Union(u, v);
            }
        }
        return cost;
    }
};
