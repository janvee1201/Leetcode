class Solution {
    public String sortVowels(String s) {
        String vowels ="aeiouAEIOU";
        StringBuilder temp = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(vowels.indexOf(s.charAt(i))!=-1){
                temp.append(s.charAt(i));
            }
        }
        char[] arr= temp.toString().toCharArray();
        Arrays.sort(arr);
        char[] chars= s.toCharArray();
        int j=0;
        for(int i=0;i<chars.length;i++){
            if(vowels.indexOf(chars[i])!=-1){
                chars[i]= arr[j++];
            }
        }
        return new String (chars);
     }
}