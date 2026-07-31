class Solution {
public:
pair<int,int> count(string&s){
int one =0,zero=0;
for(char c:s){
    if(c=='1') one++;
    else zero++;
}
return {one,zero};
}
int solve(int i , vector<string>&strs, int m , int n,  vector<vector<vector<int>>>& dp){
    if(i==strs.size()) return 0;
    if(dp[i][m][n] != -1)
    return dp[i][m][n];
    auto[one,zero]=count(strs[i]);
    int Notpick = solve(i+1,strs,m,n,dp);
    int pick = 0;
  if(zero<=m && one<=n){
    pick= 1+ solve(i+1,strs,m-zero,n-one,dp);
  }
    return dp[i][m][n] = max(pick, Notpick);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>>(m+1, vector<int>(n+1, -1))
);
        return solve(0,strs,m,n,dp);
    }
};