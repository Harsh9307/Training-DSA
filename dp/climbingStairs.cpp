#include<bits/stdc++.h>
using namespace std;

int countNumberOfWays(int n){
    if(n==0 ) return 1;
    if(n<0 ) return 0;
    int jumps=countNumberOfWays(n-1)+countNumberOfWays(n-2)+countNumberOfWays(n-3);
    return jumps;

}
// using memoization
int memo(int n,vector<int> &dp)
{
    if(n==0) return 1;
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];

    int jumps=memo(n-1,dp)+memo(n-2,dp)+memo(n-3,dp);
    return dp[n]=jumps;
}

void solve(){
    int n;
    cin>>n;


    //int ans=countNumberOfWays(n);
    // vector<int> dp(n+1,-1);
    // int ans= memo(n,dp);


    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[n];

 
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}