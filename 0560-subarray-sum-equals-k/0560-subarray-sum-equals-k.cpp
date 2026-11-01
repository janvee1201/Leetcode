class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int>mp;
        mp[0]=1;
        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
            
        }
        return cnt;
    }
};