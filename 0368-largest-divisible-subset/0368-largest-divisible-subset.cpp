class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>dp(n,1);
        vector<int>parent(n);
        sort(nums.begin(),nums.end());
        int maxlen=0;
        int last=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
        
        
            for(int prev=0;prev<i;prev++){
                if(nums[i]% nums[prev]==0 && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    parent[i]=prev;
                }
            }
        if(dp[i]>maxlen){
            last=i;
            maxlen=dp[i];
        }
        }
   int i=last;
   while(parent[i]!=i){
    ans.push_back(nums[i]);
    i=parent[i];
   }
   ans.push_back(nums[i]);
   return ans;
    }
};