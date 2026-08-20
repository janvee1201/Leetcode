class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int n = p.length();
        HashMap<Character,Integer> mp1 = new HashMap<>();
        HashMap<Character,Integer> mp2 = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            char ch = p.charAt(i);
            mp1.put(ch, mp1.getOrDefault(ch, 0) + 1);
        }
        int i = 0, j = 0;
        while(j < s.length()) {
            char ch = s.charAt(j);
            mp2.put(ch, mp2.getOrDefault(ch, 0) + 1);
            if(j - i + 1 > n) {
                char left = s.charAt(i);
                mp2.put(left, mp2.get(left) - 1);
                if(mp2.get(left) == 0)
                    mp2.remove(left);
                i++;
            }
            if(j - i + 1 == n) {
                if(mp1.equals(mp2))
                    ans.add(i);
            }
            j++;
        }
        return ans;
    }
}