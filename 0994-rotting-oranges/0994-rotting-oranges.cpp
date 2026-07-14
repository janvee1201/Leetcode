class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
      int m=grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }
            else{
                visited[i][j]=0;
            }
        }
    }
    int maxt=0;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        maxt=max(maxt,t);
        q.pop();
    
  for(int k=0;k<4;k++){
    int nr=dr[k]+r;
    int nc=dc[k]+c;
  if(nr>=0 && nc>=0 && nr<n && nc<m && 
  visited[nr][nc] ==0 && grid[nr][nc]==1){
    q.push({{nr,nc},t+1});
    visited[nr][nc]=2;
  }
  }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
     if(visited[i][j] !=2 and grid[i][j]==1)
     return -1;
        }
    }
    return maxt;
    }
};