class Solution {
public:
int n;
vector<vector<int>>grid;
vector<vector<vector<int>>>dp;
int solve(int steps, int r1, int r2){
    int c1= steps-r1;
    int c2= steps-r2;
    if(r1>=n || r2>=n||c1>=n||c2>=n|| grid[r1][c1]==-1 || grid[r2][c2]==-1){
        return -1e9;
    }
    if(steps==2*(n-1)){
        return grid[r1][c1];
    }
    if(dp[steps][r1][r2]!=-1){
        return dp[steps][r1][r2];
    }
    int gain= grid[r1][c1];
    if(r1!=r2){
        gain+= grid[r2][c2];
    }
  int best= max({ solve(steps+1,r1,r2),solve(steps+1,r1+1,r2),solve(steps+1,r1,r2+1),solve(steps+1,r1+1,r2+1)});
  
  return dp[steps][r1][r2]= best+gain;
}
    int cherryPickup(vector<vector<int>>& matrix) {
        grid= matrix;
        n= grid.size();
        dp.assign(2*(n-1),vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = solve(0,0,0);
        return max(0,ans);
    }
};