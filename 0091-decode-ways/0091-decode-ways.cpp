class Solution {
public:
int solve(string s, int indx,vector<int>&dp){
    if(indx==s.size()) return 1;
    int n=s.size();
   if(s[indx] == '0') return 0;
   if(dp[indx]!=-1) return dp[indx];
    int ans =solve(s,indx+1,dp);
     if (indx + 1 < n) {
            int num = stoi(s.substr(indx, 2));

            if (num >= 10 && num <= 26) {
                ans += solve(s, indx + 2,dp);
            }
        }
    return dp[indx]=ans;
}
    int numDecodings(string s) {
        vector<int>dp(101,-1);
       return solve(s,0,dp); 
    }
};