class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        for(char ch:s1){
            mp[ch]++;
        }
        int l=0;
        int cnt=0;
        for(int r=0;r<s2.size();r++){
            char curr= s2[r];
            if(mp.find(curr)!=mp.end()){
                mp[curr]-=1;
                if(mp[curr]==0){
                    cnt++;
                }
            }
            if(cnt==mp.size()){
                return true;
            }
            if(r>=s1.size()-1){
                char left= s2[l];
                l++;
                if(mp.find(left)!=mp.end()){
                    
                    if(mp[left]==0){
                        cnt--;
                    }
                    mp[left]++;
                }
            }
        }
        return false;
    }
};