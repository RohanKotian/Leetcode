class Solution {
public:
    int rows, cols;
    vector<vector<int>> up_table;

    int custom_binary_search(vector<pair<int, int>>& arr, int target){
        int l = 0, r = arr.size()-1;
        int res = 0;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid].first <= target){
                res = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr(n);

        for(int i=0; i<n; i++){
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());

        vector<int> org_ind(n);
        for(int i=0; i<n; i++){
            int node = arr[i].second;
            org_ind[node] = i;
        }

        int rows = n;
        int cols = log2(n) + 1;
        up_table.resize(rows, vector<int> (cols, 0));

        // First Column
        for(int node=0; node<n; node++){
            int farthest_node = custom_binary_search(arr, arr[node].first + maxDiff);
            up_table[node][0] = farthest_node;
        }

        // Remaining Columns
        for(int j=1; j<cols; j++){
            for(int node=0; node<n; node++){
                up_table[node][j] = up_table[ up_table[node][j-1] ][j-1];
            }
        }

        vector<int> res;
        for(auto& query:queries){
            int u = query[0];
            int v = query[1];

            int a = org_ind[u];
            int b = org_ind[v];
            if(a==b){
                res.push_back(0);
                continue;
            }

            if(a > b) swap(a, b);

            int jumps = 0;
            int curr  = a;

            for(int j=cols-1; j>=0; j--){
                if(up_table[curr][j] < b){
                    curr = up_table[curr][j];
                    jumps += (1<<j);    // pow(2, j)
                }
            }

            if(up_table[curr][0] >= b){
                res.push_back(jumps+1);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;        
    }
};