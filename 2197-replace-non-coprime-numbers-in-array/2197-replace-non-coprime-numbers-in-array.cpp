class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
      vector<int>st;
      for(int x:nums){
        int curr=x;
        while(st.size()){
        int g= gcd(st.back(),curr);
        if(g==1) break;
        curr= lcm(st.back(),curr);
        st.pop_back();
      }
      st.push_back(curr);
      }
      return st;
    }

};