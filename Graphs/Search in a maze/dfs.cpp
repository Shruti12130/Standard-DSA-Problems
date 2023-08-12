vector<string> ans;
    
    void solve(vector<vector<int>> &m, int n, int i, int j, string str, vector<vector<int>> vis)
    {
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 || vis[i][j]==1)
            return;
        if(i==n-1 && j==n-1){
            ans.push_back(str);
            return;
        }
        
        vis[i][j]=1;
        solve(m, n, i+1, j, str+"D", vis);
        solve(m, n, i, j-1, str+"L", vis);
        solve(m, n, i, j+1, str+"R", vis);
        solve(m, n, i-1, j, str+"U", vis);
        vis[i][j]=0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(m[0][0])
          solve(m, n, 0, 0, "", vis);
        return ans;
    }
