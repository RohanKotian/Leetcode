class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void bfs(int& n, int& m, vector<vector<bool>>& vis, vector<vector<int>>& heights, queue<pair<int, int>>& q) {
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(vis[nr][nc] || heights[nr][nc] < heights[r][c]) continue;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visP(n, vector<bool>(m, 0));
        vector<vector<bool>> visA(n, vector<bool>(m, 0));
        queue<pair<int, int>> q1, q2;


        for(int i=0; i<n; i++){
            visP[i][0] = 1;
            q1.push({i, 0});
            visA[i][m-1] = 1;
            q2.push({i, m-1});
        }
        for(int j=0; j<m; j++){
            visP[0][j] = 1;
            q1.push({0, j});
            visA[n-1][j] = 1;
            q2.push({n-1, j});
        }

        bfs(n, m, visP, heights, q1);
        bfs(n, m, visA, heights, q2);

        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visP[i][j] && visA[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};