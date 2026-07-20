class Solution {
public:
    int row, col;
    void reverse(int i, int j, vector<vector<int>>& grid){
        while(i<j){
            swap(grid[i/col][i%col], grid[j/col][j%col]);
            i++, j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        row = grid.size();
        col = grid[0].size();
        int n = row * col;
        k = k % n;

        reverse(0, n-1, grid);
        reverse(0, k-1, grid);
        reverse(k, n-1, grid);

        return grid;
    }
};