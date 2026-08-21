class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n= s.length();
        HashMap<Character,Integer>mp= new HashMap<>();
        int l=0,ans=0;
        for(int r=0;r<n;r++){
            if(mp.containsKey(s.charAt(r))){
             l= Math.max(l,mp.get(s.charAt(r))+1);
            }
            mp.put(s.charAt(r),r);
            ans= Math.max(ans,r-l+1);
        }
       return ans;

    }
}