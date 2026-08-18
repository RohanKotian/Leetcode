class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1, 1e9);

        for(auto& node:times){
            adj[node[0]].push_back({node[1], node[2]});            
        }

        queue<pair<int, int>> q;
        q.push({k, 0});

        dist[k] = 0;

        while(!q.empty()){
            auto [node, dis] = q.front();
            q.pop();

            for(auto& [adjNode, adjDist]:adj[node]){
                if(dist[adjNode] > adjDist + dis){
                    dist[adjNode] = adjDist  + dis;
                    q.push({adjNode, dist[adjNode]});
                }
            }
        }
        int res = 0;
        for(int i=1; i<=n; i++){
            if(dist[i]==1e9) return -1;
            res = max(res, dist[i]);
        }

        return res;
    }
};