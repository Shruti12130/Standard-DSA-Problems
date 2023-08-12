void solve(vector<vector<int>> &img, int sr, int sc, int prev, int color) {
        int n = img.size(), m = img[0].size();
        if(sr<0 || sc<0 || sr>=n || sc>=m || img[sr][sc]!=prev || img[sr][sc]==color) {
            return;
        }
        img[sr][sc] = color;
        solve(img, sr-1, sc, prev, color);
        solve(img, sr, sc-1, prev, color);
        solve(img, sr+1, sc, prev, color);
        solve(img, sr, sc+1, prev, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image, sr, sc, image[sr][sc], color);
        return image;
    }
