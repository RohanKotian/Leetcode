class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int> (m, 0));
        vector<vector<int>> dist(n, vector<int> (m, -1));

        queue<pair<int, int>> q;
        for(auto& src:sources){
            int r = src[0];
            int c = src[1];
            int color = src[2];

            grid[r][c] = max(grid[r][c], color);
            dist[r][c] = 0;

            q.push({r, c});
        }

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [r, c] = q.front();
                q.pop();

                int color = grid[r][c];

                for(int k=0; k<4; k++){
                    int nr = r + dirs[k][0];
                    int nc = c + dirs[k][1];

                    if(nr<0 || nr>=n || nc<0 || nc>=m)
                        continue;

                    int nd = dist[r][c]+1;

                    if(dist[nr][nc] == -1){
                        dist[nr][nc] = nd;
                        grid[nr][nc] = color;

                        q.push({nr, nc});
                    }
                    else if(dist[nr][nc]==nd){
                        grid[nr][nc] = max(grid[nr][nc], color);
                    }
                }
            }
        }
        return grid;
    }
};