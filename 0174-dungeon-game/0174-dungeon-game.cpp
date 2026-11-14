class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int r, int c, vector<vector<int>>& dungeon) {

        if(r >= n || c >= m)
            return 1e9;

        if(r == n-1 && c == m-1)
            return max(1, 1-dungeon[r][c]);

        if(dp[r][c] != -1)
            return dp[r][c];
        int need = min(solve(r+1, c, dungeon),
                       solve(r, c+1, dungeon));

        return dp[r][c] = max(1, need-dungeon[r][c]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        n = dungeon.size();
        m = dungeon[0].size();

        dp.assign(n, vector<int>(m, -1));

        return solve(0, 0, dungeon);
    }
};