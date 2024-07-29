#include<bits/stdc++.h>
using namespace std;

int step(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;

    int nop=0;
    for(int jump=1;jump<=n;jump++)
    {
        nop+=step(n-jump);
        //cout<<nop<<" ";
    }
    return nop;
}

// Memoization function
int step1(int n,vector<int> &dp)
{
    if(n==0) return 1;
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];

    int nop=0;
    for(int jump=1;jump<=n;jump++){
        nop+=step1(n-jump,dp);
    }
    return dp[n]=nop;
}

// tabulation
void solve(){
    int n;
    cin>>n;

    //int ans = step(n);
   // vector<int> dp(n+1,-1);
    //int ans = step1(n,dp);
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        for(int jump=1;jump<=i;jump++)
        {
            dp[i]=dp[i]+dp[i-jump];
        }
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
    return 0;
}