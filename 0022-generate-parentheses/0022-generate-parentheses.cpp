class Solution {
public:
void rec(string s, int open , int close,int n, vector<string>&ans){
    if(s.size()==2*n){
        ans.push_back(s);
        return;
    }
    if(open<n){
    rec(s+"(",open+1,close,n,ans);
    }
    if(close<open){
        rec(s+")",open,close+1,n,ans);
    }
     
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        rec("",0,0,n,ans);
        return ans;
        

    }
};