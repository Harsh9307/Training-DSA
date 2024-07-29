#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void dfs(int node,int vis[],vector<int> adj[],vector<int> &ls){
            vis[node]=1;
            ls.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it,vis,adj,ls);
                }
            }
        }
    public:
        vector<int> dfsTraversal(int v,vector<int> adj[]){
            int vis[v]={0};
            int start =1;

            vector<int> ls;
            dfs(start,vis,adj,ls);
            return ls;
        }
};
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> ans){
    for(int i = 0; i < ans.size();i++) cout<<ans[i]<<" ";
}
int main(){
    vector<int> adj[10];

    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    addEdge(adj,2,5);
    addEdge(adj,4,5);

    Solution obj;
    vector<int> ans = obj.dfsTraversal(6,adj);
    print(ans);

    return 0;
}