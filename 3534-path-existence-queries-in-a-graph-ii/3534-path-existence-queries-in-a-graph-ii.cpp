class Solution {
public:
    int rows, cols;
    vector<vector<int>> up_table;

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int, int>> arr(n);
        
        for(int i=0; i<n; i++){
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<int> org_ind(n);
        for(int i=0; i<n; i++){
            int ind = arr[i].second;
            org_ind[ind] = i;
        }

        rows = n;
        cols = log2(n) + 1;
        up_table.resize(rows, vector<int> (cols, 0));

        int r = 0;
        for(int l=0; l<rows; l++){
            while(r+1 < n && arr[r+1].first - arr[l].first <= maxDiff){
                r++;
            }
            up_table[l][0] = r;
        }

        for(int j=1; j<cols; j++){
            for(int node=0; node<n; node++){                
                up_table[node][j] = up_table[ up_table[node][j-1] ][j-1];
            }
        }

        int q = queries.size();
        vector<int> res(q, -1);
        for(int i=0; i<q; i++){
            int u = queries[i][0];
            int v = queries[i][1];

            int a = org_ind[u];
            int b = org_ind[v];

            if(a==b){
                res[i] = 0;
                continue;
            }

            if(a > b){
                swap(a, b);
            }

            int curr  = a;
            int jumps = 0;

            for(int j=cols-1; j>=0; j--){
                if(up_table[curr][j] < b){
                    jumps += (1<<j);
                    curr = up_table[curr][j];
                }
            }

            if(up_table[curr][0] >= b){
                res[i] = jumps+1;
            }
        }
        return res;
    }
};