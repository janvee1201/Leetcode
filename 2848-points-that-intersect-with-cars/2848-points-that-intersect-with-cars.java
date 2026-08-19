class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {

        int[] diff = new int[102];

        for(List<Integer> num : nums) {

            int start = num.get(0);
            int end = num.get(1);

            diff[start]++;

            if(end + 1 < 102) {
                diff[end + 1]--;
            }
        }

        int count = 0;
        int curr = 0;

        for(int i = 1; i < 102; i++) {

            curr += diff[i];

            if(curr > 0) {
                count++;
            }
        }

        return count;
    }
}