class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int x =left;x<=right;x++){
            bool covered= false;
        for(int i=0;i<ranges.size();i++){
           if(x>=ranges[i][0] && x<=ranges[i][1]){
            covered=true;
            break;
           }
          
        }
         if(!covered){
            return false;
           }
        }
        return true;
    }
};