class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));

        queue<vector<int>> q;
        for(auto& src:sources){
            q.push(src);
            grid[src[0]][src[1]] = src[2];
        }

        int time = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto it = q.front();
                int r = it[0];
                int c = it[1];
                int color = it[2];
                q.pop();

                for(auto& dir:dirs){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && (grid[nr][nc]==0 || (grid[nr][nc] < color && vis[nr][nc]==time))){
                        grid[nr][nc] = color;
                        vis[nr][nc] = time;
                        q.push({nr, nc, color});
                    }
                }
            }
            time++;
        }
        return grid;
    }
};