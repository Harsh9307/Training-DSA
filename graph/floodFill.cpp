#include<bits/stdc++.h>
using namespace std;

bool isvalid(int x,int y,vector<vector<int>> &vis,vector<vector<int>> &image,int originalColor){
    int row = image.size();
    int col = image[0].size();

    if(x>=0 && x<row && y>=0 && y<col && vis[x][y]!= 1  && image[x][y]==originalColor) return true;
    return false;
}
vector<vector<int>> findAns(vector<vector<int>> &image,int sr,int sc,int color){
    int rows = image.size();
    int cols = image[0].size();

    queue<pair<int,int>> q;
    vector<vector<int>> vis(rows,vector<int>(cols,0));

    int originalColor = image[sr][sc];
    q.push({sr,sc});
    vis[sr][sc]=1;
    image[sr][sc] = color;

    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
    
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(isvalid(nrow,ncol,vis,image,originalColor)){
                vis[nrow][ncol]=1;
                image[nrow][ncol]=color;
                q.push({nrow,ncol});
            }
            
        }
    }
    return image;
    
}
int main(){
    int m,n,sr,sc,color;
    cin>>m>>n>>sr>>sc>>color;

    vector<vector<int>> image(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>image[i][j];
        }
    }
    vector<vector<int>> ans = findAns(image,sr,sc,color);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}