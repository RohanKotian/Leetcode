class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto& p:points){
            int dist = p[0] * p[0] + p[1] * p[1];
            if(pq.size() < k){
                pq.push({dist, p});
            }
            else if(dist < pq.top().first){
                pq.pop();
                pq.push({dist, p});
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};