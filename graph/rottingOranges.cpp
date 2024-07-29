#include<bits/stdc++.h>
using namespace std;

bool isValid(int x,int y,vector<vector<int>> grid,vector<vector<int>> &vis){
    int rows = grid.size();
    int cols = grid[0].size();

    if(x>=0 && x<rows && y>=0 && y<cols && grid[x][y]!=0 && vis[x][y]!= 1) return true;
    return false;
}

int findAns(vector<vector<int>> &grid){
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> vis(rows,vector<int>(cols));

    int time =0;
    queue<pair<int,pair<int,int>>> q;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]==2){
                vis[i][j]=1;
                q.push({0,{i,j}});
            }
        }
    }

    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};

    while(!q.empty()){
        int r = q.front().second.first;
        int c = q.front().second.second;
        time = q.front().first;
        q.pop();

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(isValid(nrow,ncol,grid,vis)){
                    q.push({time+1,{nrow,ncol}});
                    vis[nrow][ncol] =1;
                }
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(vis[i][j]==0 && grid[i][j]==1) return -1;
        }
    }
    return time;

}
int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    int ans = findAns(grid);
    cout<<ans<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

        }
    }
    return 0;
}