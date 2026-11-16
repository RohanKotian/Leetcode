class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev (n);

        for(int i=0; i<n; i++){
            prev[i] = matrix[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            vector<int> curr(n);

            for(int j=n-1; j>=0; j--){
                int left = 1e9, right = 1e9;
                int down = prev[j];

                if(j-1 >= 0){
                    left = prev[j-1];
                }
                if(j+1 < n){
                    right = prev[j+1];
                }

                curr[j] = matrix[i][j] + min({down, left, right});
            }
            prev = curr;
        }

        int res = *min_element(prev.begin(), prev.end());
        return res;
    }
};