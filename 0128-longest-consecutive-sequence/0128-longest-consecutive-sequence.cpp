class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int longest=0;
        for(int num: st){
            if(st.contains(num-1)){
                continue;
            }
            int currlen=1;
            int next= num+1;
            while(st.contains(next)){
                currlen++;
                next++;
            }
            longest= max(longest,currlen);
        }
        return longest;
    }
};