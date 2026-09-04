class Solution {
public:
void rec(vector<int>& nums, vector<vector<int>>&ans, vector<int>&ds, vector<int>&freq){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    unordered_set<int>st;
    for(int i=0;i<nums.size();i++){
        if(!freq[i] && !st.count(nums[i])){
            st.insert(nums[i]);
            ds.push_back(nums[i]);
            freq[i]=1;
            rec(nums,ans,ds,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(nums.size(),0);
        rec(nums,ans,ds,freq);
        return ans;
    }
};