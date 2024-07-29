#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> bfsOfGraph(int v ,vector<int> adj[]){
            vector<int> vis(v,0);
            queue<int> q;
            vis[0]=1;
            q.push(0);

            vector<int> ans;
            while(!q.empty()){
                int size = q.size();
                int curr = q.front();
                q.pop();
                ans.push_back(curr);

                for(auto it: adj[curr]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            return ans;
        }
};
void print(vector<int> &ans){
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    print(ans);

    return 0;
}