
class Solution {
    public long smallestNumber(long num) {

        if (num == 0) return 0;

        boolean negative = num < 0;

        String s = String.valueOf(Math.abs(num));

        if (!negative) {

            char[] arr = s.toCharArray();
            Arrays.sort(arr);

            if (arr[0] == '0') {
                for (int i = 1; i < arr.length; i++) {
                    if (arr[i] != '0') {
                        char temp = arr[0];
                        arr[0] = arr[i];
                        arr[i] = temp;
                        break;
                    }
                }
            }

            return Long.parseLong(new String(arr));

        } else {

            Character[] arr = new Character[s.length()];

            for (int i = 0; i < s.length(); i++) {
                arr[i] = s.charAt(i);
            }

            Arrays.sort(arr, Collections.reverseOrder());

            StringBuilder sb = new StringBuilder();

            for (char ch : arr) {
                sb.append(ch);
            }

            return -Long.parseLong(sb.toString());
        }
    }
}