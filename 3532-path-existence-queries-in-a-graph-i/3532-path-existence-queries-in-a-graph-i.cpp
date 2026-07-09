class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> rank(n, 0);

        for(int i=1; i<n; i++){            
            if(nums[i] - nums[i-1] <= maxDiff){
                rank[i] = rank[i-1];
            }
            else{
                rank[i] = i;
            }
        }

        vector<bool> res(queries.size());
        for(int i=0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];

            res[i] = rank[u]==rank[v];            
        }
        return res;
    }
};