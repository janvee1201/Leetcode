class Solution {
public:
    int lengthOfLongestSubstring(string s) {
unordered_map<char,int>mp;
int l=0,ans=0;
int n=s.size();
for(int r=0;r<n;r++){
    if(mp.count(s[r])){
l=max(l,mp[s[r]]+1);
    }
    mp[s[r]]=r;
    ans=max(ans,r-l+1);
    }
return ans;
    }
};