#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid,int row,int col)
{
    for(int r=row-1;r>=0;r--)
    {
        if(col ==0) return grid[r][col];

        int upperDiagonal = (r > 1 && col > 1) ? grid[r][col] + solve(grid,r-1,col-1)INT_MAX;
        int sameRow = (col > 1) ? grid[r][col] + solve(grid, r,col-1):INT_MAX;
        int lowerDiagonal = (r<row) ? grid[r][col] + solve(grid,r+1,col-1):INT_MAX;

        int ans=  min(uperDiagonal, sameRow);
        return min(ans, lowerDiagonal);
    }
}

int main(){
    vector<vector<int>> grid ={
        {1,3,1},
        {1,5,1},
        {4,2,1}
        };

    int row= grid.size();
    int col= grid[0].size();

    int ans= solve(grid,row,col);
    cout<<ans<<endl;

    return 0;
}