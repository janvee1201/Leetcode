class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int diff[]= new int[n];
        for(int [] num : bookings ){
            int start= num[0];
            int end= num[1];
            int seats= num[2];
            diff[start-1]+=seats;
            if(end<n){
                diff[end]-=seats;
            }
        }
        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        return diff;
    }
}