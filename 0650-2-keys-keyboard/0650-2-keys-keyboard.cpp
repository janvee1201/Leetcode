class Solution {
public:
    int minSteps(int n) {
        int cnt=0;
        if(n==1) return 0;
        for(int factor=2;factor*factor<=n;factor++){
            while(n%factor==0){
                cnt+=factor;
                n/=factor;
            }
        }
        if(n>1){
            cnt+=n;
        }
return cnt;
    }
};