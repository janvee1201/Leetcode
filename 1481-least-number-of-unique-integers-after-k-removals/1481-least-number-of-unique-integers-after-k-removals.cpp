class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        vector<int>freq;
        for(auto &it:mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        int cnt=freq.size();
        for(int i:freq){
            if(k>=i){
                k-=i;
                cnt--;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};