class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<bool> vis(n+1, false);

        for(auto& road:roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        q.push(1);
        vis[1] = true;

        int res = 1e9;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& [v, w]:adj[node]){
                res = min(res, w);
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        return res;
    }
};