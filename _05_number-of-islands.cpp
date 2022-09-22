class Solution {
public:
    void recur(vector<vector<char>>& grid, int i, int j, int &ans) {
        if (i < 0 || i > grid.size()-1 ||
           j < 0 || j > grid[0].size()-1)
            return ;
        if (grid[i][j] != '1') 
            return ;
        grid[i][j] = '2';
        recur(grid, i+1, j, ans);
        recur(grid, i-1, j, ans);
        recur(grid, i, j+1, ans);
        recur(grid, i, j-1, ans);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i=0; i < grid.size(); ++i) {
            for (int j=0; j < grid[0].size(); ++j) {

                if (grid[i][j] == '1') {
                    recur(grid, i, j, ans);
                    ans++;
                }
            }
        }
        return ans;
    }
};
