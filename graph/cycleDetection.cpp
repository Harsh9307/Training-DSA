#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &vis,vector<int> adj[],int node,int parent){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(vis,adj,it,node)) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}
bool isCycle(int v,vector<int> adj[]){
    vector<int> vis(v);
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(vis,adj,i,-1)) return true;
        }
    }
    return false;
}
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    
    bool ans = isCycle(5, adj);
    cout<<ans<<endl;
    return 0;
}