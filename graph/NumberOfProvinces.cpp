#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[],vector<int> &vis,int node){
    vis[node]=1;

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(adj,vis,it);
        }
    }
}
int f(int v,vector<vector<int>> &isConnected){
    int r = isConnected.size();

    vector<int> adj[v];
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            if(i!=j && isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }            
        }
    }

    vector<int> vis(v);
    int cnt=0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(adj,vis,i);
            cnt++;
        }
    }
    return cnt;

}
int main(){
    int n;
    cin>>n;

    vector<vector<int>> isConnected(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>isConnected[i][j];
        }
    }
    int ans = f(n,isConnected);
    cout<<ans<<endl;
    return 0;
}